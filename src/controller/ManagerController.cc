#include "../include/ManagerController.h"
#include "../include/NewProjectController.h"
#include "../include/ImagesController.h"
#include <iostream>
#include <fstream>
#include "../include/json/document.h"
#include "../include/json/writer.h"
#include "../include/json/stringbuffer.h"
using namespace std;
using namespace rapidjson;

ManagerController::ManagerController(Glib::RefPtr<Gtk::Application> app){
   ManagerController::readDocument();
   ManagerController::app = app;
   auto refBuilder = Gtk::Builder::create();
   try{
      refBuilder->add_from_file("src/view/manager.glade");
   }catch(const Glib::FileError& ex){
      std::cerr << "FileError: " << ex.what() << std::endl;
   }
   refBuilder->get_widget("GtkApplicationWindow", ManagerController::managerWindow);
   managerWindow->show_all_children();
   managerWindow->signal_hide().connect(sigc::mem_fun(*this, &ManagerController::saveDocument));
   refBuilder->get_widget("NewButton", ManagerController::newButton);
   ManagerController::newButton->signal_clicked().connect( sigc::mem_fun(*this, &ManagerController::on_button_clicked) );
   refBuilder->get_widget("Salir", ManagerController::exitButton);
   ManagerController::exitButton->signal_clicked().connect( sigc::mem_fun(*this, &ManagerController::on_exit_clicked) );

   refBuilder->get_widget("ProjectList", ManagerController::projectList);
   projectList->signal_row_activated().connect(sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &ManagerController::selected), ""));

   refreshProjects();
}

void ManagerController::on_button_clicked(){
   NewProjectController newProject(this);
   newProject.getWindow()->run();
   
}

void ManagerController::on_exit_clicked(){
   managerWindow->hide();
}

Gtk::ApplicationWindow* ManagerController::getWindow(){
  return managerWindow;
}

ManagerController::~ManagerController(){

}

void ManagerController::refreshProjects(){
   int q = projectList->get_children().size();
   while (--q >= 0){
      Gtk::Widget* b = (Gtk::Widget*)projectList->get_children().at(q);
      projectList->remove(*b);
   }

   for(unsigned i=0; i < projectNames.size(); i++){
      Gtk::Label *label = Gtk::manage(new Gtk::Label(projectNames[i]));
      Gtk::Box *box = Gtk::manage(new Gtk::Box());
      box->pack_start(*label);
      Gtk::ListBoxRow *row = Gtk::manage(new Gtk::ListBoxRow());
      row->add(*box);
      row->set_size_request(100,50);
      projectList->append(*row);
   }
   projectList->show_all_children();
}

void ManagerController::readDocument(){
   // Reading the file
   string line, all;
   ifstream myfile ("data/GeneralData.gnrl");
   if (myfile.is_open()){
      // Concat all lines
      while (getline(myfile,line)){
         all += line;
      }
      
      // Parse JSON
      Document d;
      ParseResult ok = d.Parse(all.c_str());

      if(!ok){
         ManagerController::numberOfProjects = 0;
         ManagerController::roleActive = "RESEARCHER";
         ManagerController::languageActive = "EN";
         ManagerController::projectIdGenerator = 1;
      }else{
         // Setting global variables
         Value& s = d["numberOfProjects"];
         ManagerController::numberOfProjects = s.GetInt();
         s = d["roleActive"];
         ManagerController::roleActive = s.GetString();
         s = d["languageActive"];
         ManagerController::languageActive = s.GetString();
         s = d["projectIdGenerator"];
         ManagerController::projectIdGenerator = s.GetInt();
         s = d["projects"];
         if(s.IsArray())
            for (rapidjson::Value::ConstValueIterator itr = s.Begin(); itr != s.End(); ++itr) {
               const rapidjson::Value& attribute = *itr;
               assert(attribute.IsString()); // each attribute is an object
               ManagerController::projectNames.push_back(attribute.GetString());
            }
         s = d["profiles"];
         if(s.IsArray())
            for (rapidjson::Value::ConstValueIterator itr = s.Begin(); itr != s.End(); ++itr) {
               const rapidjson::Value& attribute = *itr;
               assert(attribute.IsString()); // each attribute is an object
               ManagerController::profileNames.push_back(attribute.GetString());
            }
         myfile.close();
      }
   }else{
      ManagerController::numberOfProjects = 0;
      ManagerController::roleActive = "RESEARCHER";
      ManagerController::languageActive = "EN";
      ManagerController::projectIdGenerator = 1;
   }
}

void ManagerController::saveDocument(){
   ofstream myfile ("data/GeneralData.gnrl", std::ios_base::trunc);
   if (myfile.is_open()){
      Document d;
      d.SetObject();
      Value numberProj;
      numberProj.SetInt(ManagerController::numberOfProjects);
      Value roleActive;
      roleActive.SetString(ManagerController::roleActive.c_str(),ManagerController::roleActive.length(),d.GetAllocator());
      Value languageActive;
      languageActive.SetString(ManagerController::languageActive.c_str(),ManagerController::languageActive.length(),d.GetAllocator());
      Value projectIdGenerator(ManagerController::projectIdGenerator);

      d.AddMember("numberOfProjects",numberProj,d.GetAllocator());
      d.AddMember("roleActive",roleActive,d.GetAllocator());
      d.AddMember("languageActive",languageActive,d.GetAllocator());
      d.AddMember("projectIdGenerator",projectIdGenerator,d.GetAllocator());

      Value a;
      a.SetArray();
      
      for(unsigned i=0; i < projectNames.size(); i++){
         Value name;
         name.SetString(projectNames[i].c_str(),projectNames[i].length(),d.GetAllocator());
         a.PushBack(name,d.GetAllocator());
      }

      d.AddMember("projects",a,d.GetAllocator());
      
      a.SetArray();
      a.Clear();
      
      for(unsigned i=0; i < profileNames.size(); i++){
         Value name;
         name.SetString(profileNames[i].c_str(),profileNames[i].length(),d.GetAllocator());
         a.PushBack(name,d.GetAllocator());
      }

      d.AddMember("profiles",a,d.GetAllocator());

      StringBuffer buffer;
      Writer<StringBuffer> writer(buffer);
      d.Accept(writer);

      myfile << buffer.GetString();
      myfile.close();
   }else
      cout << "Unable to write file";
}

void ManagerController::selected(Gtk::ListBoxRow* lista, Glib::ustring path){
   Gtk::Label* l = (Gtk::Label*)((Gtk::Box*)lista->get_child())->get_children()[0];
   ImagesController* images = new ImagesController(l->get_text(),app);
   app->add_window(*images->imagesWindow);
   managerWindow->hide();

   //getWindow()->hide();
}