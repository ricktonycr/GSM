#include "../include/ManagerController.h"
#include "../include/NewProjectController.h"
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
   projectList->signal_row_selected().connect(sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &ManagerController::selected), "projectPaths[i]"));

   for(unsigned i=0; i < projectNames.size(); i++){
      Gtk::Label *label = Gtk::manage(new Gtk::Label(projectNames[i]));
      Gtk::Box *box = Gtk::manage(new Gtk::Box());
      box->pack_start(*label);
      Gtk::ListBoxRow *row = Gtk::manage(new Gtk::ListBoxRow());
      row->add(*box);
      row->set_size_request(100,50);
      //row->signal_selection_received();
      projectList->append(*row);
   }
   projectList->show_all_children();
   
}

void ManagerController::on_button_clicked(){
   NewProjectController newProject;
   newProject.getWindow()->set_parent(*managerWindow);
   newProject.getWindow()->run();
   
   std::cout << "The Button was clicked." << std::endl;
}

void ManagerController::on_exit_clicked(){
   managerWindow->hide();
}

Gtk::ApplicationWindow* ManagerController::getWindow(){
  return managerWindow;
}

ManagerController::~ManagerController(){

}

void ManagerController::readDocument(){
   // Reading the file
   string line, all;
   ifstream myfile ("GeneralData.gnrl");
   if (myfile.is_open()){
      // Concat all lines
      while (getline(myfile,line)){
         all += line;
      }
      
      // Parse JSON
      Document d;
      d.Parse(all.c_str());

      // Setting global variables
      Value& s = d["numberOfProjects"];
      ManagerController::numberOfProjects = s.GetInt();
      s = d["roleActive"];
      ManagerController::roleActive = s.GetString();
      s = d["languageActive"];
      ManagerController::languageActive = s.GetString();
      s = d["projectIdGenerator"];
      ManagerController::projectIdGenerator = s.GetInt();
      myfile.close();
   }else{
      ManagerController::numberOfProjects = 0;
      ManagerController::roleActive = "RESEARCHER";
      ManagerController::languageActive = "EN";
      ManagerController::projectIdGenerator = 1;
      ManagerController::projectNames.push_back("hola");
      ManagerController::projectPaths.push_back("./");
   }
}

void ManagerController::saveDocument(){
   ofstream myfile ("GeneralData.gnrl", std::ios_base::app);
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

      Value a(kArrayType);
      for(unsigned i=0; i < projectNames.size(); i++){
         Value v(kObjectType);
         Value id;
         Value path;
         id.SetString(projectNames[i].c_str(),projectNames[i].length(),d.GetAllocator());
         path.SetString(projectPaths[i].c_str(),projectPaths[i].length(),d.GetAllocator());
         v.AddMember("name",id,d.GetAllocator());
         v.AddMember("path",path,d.GetAllocator());
         a.PushBack(v,d.GetAllocator());
      }

      d.AddMember("projects",a,d.GetAllocator());
      

      StringBuffer buffer;
      Writer<StringBuffer> writer(buffer);
      d.Accept(writer);

      myfile << buffer.GetString();
      myfile.close();
   }else
      cout << "Unable to write file";
}

void ManagerController::selected(Glib::ustring path){
   cout << path << endl;
}