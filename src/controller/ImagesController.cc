#include "../include/ImagesController.h"
#include "../include/PointsController.h"
#include "../include/ImageResume.h"
#include <gdkmm/pixbuf.h>
#include <iostream>
#include <fstream>
#include "../include/json/document.h"
#include "../include/json/writer.h"
#include "../include/json/stringbuffer.h"
using namespace std;
using namespace rapidjson;
//using namespace std;

ImagesController::ImagesController(string path,Glib::RefPtr<Gtk::Application> app){
   completePath = "data/projects/" + path + ".gsmpj";
   ImagesController::app = app;
   auto refBuilder = Gtk::Builder::create();
   try{
      refBuilder->add_from_file("src/view/images.glade");
   }
   catch (const Glib::FileError &ex){
      std::cerr << "FileError: " << ex.what() << std::endl;
   }
   refBuilder->get_widget("grid", ImagesController::imagesWindow);
   refBuilder->get_widget("nuevo", ImagesController::newButton);
   refBuilder->get_widget("FlowBox", ImagesController::flow);
   refBuilder->get_widget("Eliminar", ImagesController::eliminar);
   refBuilder->get_widget("Cerrar", ImagesController::cerrar);
   refBuilder->get_widget("Editar", ImagesController::editar);
   newButton->signal_clicked().connect(sigc::mem_fun(*this, &ImagesController::on_button_clicked));
   eliminar->signal_clicked().connect(sigc::mem_fun(*this, &ImagesController::on_delete_clicked));
   imagesWindow->signal_hide().connect(sigc::mem_fun(*this, &ImagesController::on_hide_clicked));
   cerrar->signal_clicked().connect(sigc::mem_fun(*this, &ImagesController::on_close_clicked));
   editar->signal_clicked().connect(sigc::mem_fun(*this, &ImagesController::on_edit_clicked));
   ImagesController::readDocument();
   imagesWindow->show_all_children();
   imagesWindow->show();
   cout << "asasaasasa" << endl;
}

void ImagesController::on_button_clicked(){
   Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FILE_CHOOSER_ACTION_OPEN);
   dialog.set_transient_for(*imagesWindow);
   //Add response buttons the the dialog:
   dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
   dialog.add_button("_Open", Gtk::RESPONSE_OK);

   //Add filters, so that only certain file types can be selected:
   Glib::RefPtr<Gtk::FileFilter> filter_text2 = Gtk::FileFilter::create();
   filter_text2->set_name("JPEG");
   filter_text2->add_mime_type("image/jpeg");
   dialog.add_filter(filter_text2);
   Glib::RefPtr<Gtk::FileFilter> filter_text = Gtk::FileFilter::create();
   filter_text->set_name("PNG");
   filter_text->add_mime_type("image/png");
   dialog.add_filter(filter_text);
   /*
    Glib::RefPtr filter_cpp = Gtk::FileFilter::create();
    filter_cpp->set_name("C/C++ files");
    filter_cpp->add_mime_type("text/x-c");
    filter_cpp->add_mime_type("text/x-c++");
    filter_cpp->add_mime_type("text/x-c-header");
    dialog.add_filter(filter_cpp);

    Glib::RefPtr filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);*/

   //Show the dialog and wait for a user response:
   int result = dialog.run();

   //Handle the response:
   switch (result){
   case (Gtk::RESPONSE_OK):{
      // The user selects a file
      std::string filename = dialog.get_filename();
      auto buff = Gdk::Pixbuf::create_from_file(filename, 200, 200, true);
      auto copy = Gdk::Pixbuf::create_from_file(filename);
      idGenerator++;
      string file1 = "data/imageCache/" + to_string(id) + "_" + to_string(idGenerator) + ".gsmii";
      buff->save(file1, "jpeg");
      string file2 = "data/originalImage/" + to_string(id) + "_" + to_string(idGenerator) + ".gsmoi";
      copy->save(file2, "jpeg");

      ImageResume *image = Gtk::manage(new ImageResume(buff));
      image->id = idGenerator;
      image->name = dialog.get_file().get()->get_basename();
      image->state = "CREATED";
      image->iconURL = file1;
      Gtk::FlowBoxChild *b = Gtk::manage(new Gtk::FlowBoxChild());
      Gtk::Image* w = (Gtk::Image*)image;
      b->add(*w);
      flow->add(*b);
      flow->show_all_children();
      break;
   }
   case (Gtk::RESPONSE_CANCEL):{
      // The user clicked cancel
      std::cout << "Cancel clicked." << std::endl;
      break;
   }
   default:{
      // The user closed the dialog box
      std::cout << "Unexpected button clicked." << std::endl;
      break;
   }
   }
}

void ImagesController::on_delete_clicked(){
   vector<Gtk::FlowBoxChild *> sel = flow->get_selected_children();
   if(sel.size()>0){
      Gtk::FlowBoxChild *c = sel.at(0);
      ImageResume* resum = (ImageResume*) c->get_children().at(0);
      int imId = resum->id;
      cout << imId << endl;
      cout << resum->name << endl;
      string file = "data/imageCache/" + to_string(id) + "_" + to_string(imId) + ".gsmii";
      remove(file.c_str());
      file = "data/originalImage/" + to_string(id) + "_" + to_string(imId) + ".gsmoi";
      remove(file.c_str());
      flow->remove(*c);
      flow->show_all_children();
   }
}

void ImagesController::readDocument(){
   // Reading the file
   string line, all;
   ifstream myfile(completePath);
   if (myfile.is_open()){
      // Concat all lines
      while (getline(myfile, line)){
         all += line;
      }

      // Parse JSON
      Document d;
      ParseResult ok = d.Parse(all.c_str());

      if (!ok){
         Glib::ustring message("No es posible abrir el proyecto");
         Gtk::MessageDialog dialog("Error", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
         dialog.set_secondary_text(message);
         dialog.set_position(Gtk::WIN_POS_CENTER);
         dialog.run();
         imagesWindow->hide();
      }else{
         // Setting global variables
         Value &s = d["id"];
         ImagesController::id = s.GetInt();
         s = d["idGenerator"];
         ImagesController::idGenerator = s.GetInt();
         s = d["name"];
         ImagesController::name = s.GetString();
         s = d["nameProfile"];
         ImagesController::profile = s.GetString();
         s = d["imageResumes"];
         if (s.IsArray())
            for (rapidjson::Value::ConstValueIterator itr = s.Begin(); itr != s.End(); ++itr){
               const rapidjson::Value &attribute = *itr;
               assert(attribute.IsObject()); // each attribute is an object
               string p = attribute["iconURL"].GetString();
               auto buff = Gdk::Pixbuf::create_from_file(p);
               ImageResume* imgR = Gtk::manage(new ImageResume(buff));
               imgR->id = attribute["id"].GetInt();
               imgR->iconURL = attribute["iconURL"].GetString();
               imgR->name = attribute["name"].GetString();
               imgR->state = attribute["state"].GetString();
               Gtk::FlowBoxChild *b = Gtk::manage(new Gtk::FlowBoxChild());
               Gtk::Image* w = (Gtk::Image*)imgR;
               b->add(*w);
               flow->add(*b);
               flow->show_all_children();
            }
         myfile.close();
      }
   }else{
      Glib::ustring message("No es posible abrir el proyecto");
      Gtk::MessageDialog dialog("Error", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
      dialog.set_secondary_text(message);
      dialog.set_position(Gtk::WIN_POS_CENTER);
      dialog.run();
      imagesWindow->hide();
   }
}

void ImagesController::on_hide_clicked(){
   ImagesController::writeDocument();
}

void ImagesController::writeDocument(){
   string path = "data/projects/";
      path = path + name + ".gsmpj";
      ofstream myfile(path, std::ios_base::trunc);
      if(myfile.is_open()){
         Document d;
         d.SetObject();
         Value id;
         id.SetInt(ImagesController::id);
         Value name;
         name.SetString(ImagesController::name.c_str(),ImagesController::name.length(),d.GetAllocator());
         Value prof;
         prof.SetString(ImagesController::profile.c_str(),ImagesController::profile.length(),d.GetAllocator());
         Value generator;
         generator.SetInt(ImagesController::idGenerator);
         Value imageResumes;
         imageResumes.SetArray();

         int qw = 0;
         while(qw<flow->get_children().size()){
            Gtk::FlowBoxChild* child = (Gtk::FlowBoxChild*)flow->get_children().at(qw);
            ImageResume* resume = (ImageResume*) child->get_children().at(0);
            Value obj;
            obj.SetObject();
            Value Iid;
            Iid.SetInt(resume->id);
            Value Iicon;
            Iicon.SetString(resume->iconURL.c_str(),resume->iconURL.length(),d.GetAllocator());
            Value Iname;
            Iname.SetString(resume->name.c_str(),resume->name.length(),d.GetAllocator());
            Value Istate;
            Istate.SetString(resume->state.c_str(),resume->state.length(),d.GetAllocator());
            obj.AddMember("id",Iid,d.GetAllocator());
            obj.AddMember("iconURL",Iicon,d.GetAllocator());
            obj.AddMember("name",Iname,d.GetAllocator());
            obj.AddMember("state",Istate,d.GetAllocator());
            imageResumes.PushBack(obj,d.GetAllocator());
            qw++;
         }

         d.AddMember("id", id, d.GetAllocator());
         d.AddMember("name", name, d.GetAllocator());
         d.AddMember("nameProfile", prof, d.GetAllocator());
         d.AddMember("idGenerator", generator, d.GetAllocator());
         d.AddMember("imageResumes", imageResumes, d.GetAllocator());

         StringBuffer buffer;
         Writer<StringBuffer> writer(buffer);
         d.Accept(writer);

         myfile << buffer.GetString();
         myfile.close();
      }
}

void ImagesController::on_close_clicked(){
   cout << "Cerrando"  << endl;
   
   imagesWindow->hide();
}

void ImagesController::on_edit_clicked(){
   vector<Gtk::FlowBoxChild *> sel = flow->get_selected_children();
   if(sel.size()>0){
      Gtk::FlowBoxChild *c = sel.at(0);
      ImageResume* resum = (ImageResume*) c->get_children().at(0);
      int imId = resum->id;
      
      PointsController* images = new PointsController(id,imId);
      app->add_window(*images->pointsWindow);
      //imagesWindow->hide();
   }
}