#include "../include/NewProfileController.h"
#include <iostream>
#include "../include/json/document.h"
#include "../include/json/writer.h"
#include "../include/json/stringbuffer.h"
#include <fstream>
using namespace std;
using namespace rapidjson;

NewProfileController::NewProfileController(ManagerController* manager, NewProjectController* project){
   auto refBuilder = Gtk::Builder::create();
   mc = manager;
   prj = project;
   profileNames = &mc->profileNames;
   
   try{
      refBuilder->add_from_file("src/view/newProfile.glade");
   }catch(const Glib::FileError& ex){
      std::cerr << "FileError: " << ex.what() << std::endl;
   }
   refBuilder->get_widget("NewProfile", NewProfileController::managerWindow);
   managerWindow->set_transient_for(*prj->getWindow());
   refBuilder->get_widget("Cancelar", NewProfileController::cancelButton);
   refBuilder->get_widget("Aceptar", NewProfileController::aceptButton);
   refBuilder->get_widget("Add", NewProfileController::add);
   refBuilder->get_widget("Lista", NewProfileController::items);
   refBuilder->get_widget("Nombre", NewProfileController::nombre);
   NewProfileController::cancelButton->signal_clicked().connect( sigc::mem_fun(*this, &NewProfileController::on_cancel_clicked) );
   NewProfileController::aceptButton->signal_clicked().connect( sigc::mem_fun(*this, &NewProfileController::on_acept_clicked) );
   NewProfileController::add->signal_clicked().connect( sigc::mem_fun(*this, &NewProfileController::on_add_clicked) );

   items->set_selection_mode(Gtk::SELECTION_NONE);

   Gtk::Box *box = Gtk::manage(new Gtk::Box());
   Gtk::Label * l1 = new Gtk::Label("Atributo");
   Gtk::Label * l2 = new Gtk::Label("Valores");
   Gtk::Label * l3 = new Gtk::Label("Obligatorio");
   box->pack_start(*l1);
   box->pack_start(*l2);
   box->pack_start(*l3);
   box->set_homogeneous(true);

   Gtk::ListBoxRow *row = Gtk::manage(new Gtk::ListBoxRow());
   row->add(*box);
   row->set_size_request(100,50);
   items->append(*row);
   items->show_all_children();
}

NewProfileController::~NewProfileController(){

}


Gtk::Dialog* NewProfileController::getWindow(){
  return managerWindow;
}

void NewProfileController::on_cancel_clicked(){
   managerWindow->hide();
}

void NewProfileController::on_acept_clicked(){
   string name = nombre->get_text();

   if(name.length() == 0){
      Glib::ustring message("No se ingresó un nombre válido");
      Gtk::MessageDialog dialog("Error", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
      dialog.set_secondary_text(message);
      dialog.set_position(Gtk::WIN_POS_CENTER);
      dialog.run();
   }else{
      string path = "data/profiles/";
      path = path + name + ".gsmpf";
      ofstream myfile(path, std::ios_base::trunc);
      if(myfile.is_open()){
         Document d;
         d.SetObject();
         
         Value nam;
         nam.SetString(name.c_str(),name.length(),d.GetAllocator());
         Value profiles;
         profiles.SetArray();

         // Llenar perfiles
         int q = 1;
         while (q<items->get_children().size()){
            Gtk::ListBoxRow *row = (Gtk::ListBoxRow*)items->get_children().at(q);
            Gtk::Box *box = (Gtk::Box*)row->get_children().at(0);
            Gtk::Entry* entry = (Gtk::Entry*)box->get_children().at(0);
            string atribute = entry->get_text();
            entry = (Gtk::Entry*)box->get_children().at(1);
            string values = entry->get_text();
            Gtk::CheckButton* check = (Gtk::CheckButton*) box->get_children().at(2);
            bool mandatory = check->get_active();
            Value o;
            o.SetObject();
            Value n;
            n.SetString(atribute.c_str(),atribute.length(),d.GetAllocator());
            o.AddMember("name",n,d.GetAllocator());
            Value t;
            t.SetString("string",6,d.GetAllocator());
            o.AddMember("type",t,d.GetAllocator());
            q++;
            Value v;
            v.SetArray();
            vector<string> valores = NewProfileController::splitown(values,",");
            int q = 0;
            while(q<valores.size()){
               Value w;
               w.SetString(valores.at(q).c_str(),valores.at(q).length(),d.GetAllocator());
               v.PushBack(w,d.GetAllocator());
               q++;
            }
            o.AddMember("values",v,d.GetAllocator());

            Value m;
            m.SetBool(mandatory);
            o.AddMember("mandatory",m,d.GetAllocator());
         }

         d.AddMember("name", nam, d.GetAllocator());
         d.AddMember("items",profiles,d.GetAllocator());

         profileNames->push_back(name);
         prj->refreshCombo();
         StringBuffer buffer;
         Writer<StringBuffer> writer(buffer);
         d.Accept(writer);

         myfile << buffer.GetString();
         myfile.close();
         managerWindow->hide();
      }
   }
}

void NewProfileController::on_add_clicked(){
   bool _void = false;
   int q = 1;
   while (q<items->get_children().size()){
      Gtk::ListBoxRow *row = (Gtk::ListBoxRow*)items->get_children().at(q);
      Gtk::Box *box = (Gtk::Box*)row->get_children().at(0);
      Gtk::Entry* entry = (Gtk::Entry*)box->get_children().at(0);
      string temp = entry->get_text();
      if(temp.length() == 0){
         _void = true;
      }
      q++;
   }

   if(!_void){
      Gtk::Box *box = Gtk::manage(new Gtk::Box());
      Gtk::Entry* entry = new Gtk::Entry();
      Gtk::Entry* entry2 = new Gtk::Entry();
      Gtk::CheckButton* check = new Gtk::CheckButton();
      check->set_halign(Gtk::ALIGN_CENTER);
      box->pack_start(*entry);
      box->pack_start(*entry2);
      box->pack_start(*check);
      box->set_spacing(10);
      box->set_homogeneous(true);

      Gtk::ListBoxRow *row = Gtk::manage(new Gtk::ListBoxRow());
      row->add(*box);
      row->set_size_request(100,50);
      items->append(*row);
      items->show_all_children();
   }
}

std::vector<string> NewProfileController::splitown(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}
