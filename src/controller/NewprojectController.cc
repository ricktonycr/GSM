#include "../include/NewProjectController.h"
#include "../include/NewProfileController.h"
#include <iostream>
#include "../include/json/document.h"
#include "../include/json/writer.h"
#include "../include/json/stringbuffer.h"
#include <fstream>
using namespace std;
using namespace rapidjson;

NewProjectController::NewProjectController(ManagerController* manager){
   auto refBuilder = Gtk::Builder::create();
   mc = manager;
   NewProjectController::projectNames = &manager->projectNames;
   NewProjectController::profileNames = &manager->profileNames;
   NewProjectController::projectIdGenerator = &manager->projectIdGenerator;
   try{
      refBuilder->add_from_file("src/view/newProject.glade");
   }catch(const Glib::FileError& ex){
      std::cerr << "FileError: " << ex.what() << std::endl;
   }
   refBuilder->get_widget("GtkDialog", NewProjectController::managerWindow);
   managerWindow->set_transient_for(*mc->getWindow());
   refBuilder->get_widget("Cancelar", NewProjectController::cancelButton);
   refBuilder->get_widget("Aceptar", NewProjectController::aceptButton);
   refBuilder->get_widget("Nombre", NewProjectController::entry);
   refBuilder->get_widget("profilesCombo", NewProjectController::combo);
   refBuilder->get_widget("newProfile", NewProjectController::newProfile);
   NewProjectController::cancelButton->signal_clicked().connect( sigc::mem_fun(*this, &NewProjectController::on_cancel_clicked) );
   NewProjectController::aceptButton->signal_clicked().connect( sigc::mem_fun(*this, &NewProjectController::on_acept_clicked) );
   NewProjectController::newProfile->signal_clicked().connect( sigc::mem_fun(*this, &NewProjectController::on_newProfile_clicked) );
   managerWindow->show_all_children();

   refreshCombo();
}

void NewProjectController::refreshCombo(){
   int i = 0;
   combo->remove_all();
   while(i<profileNames->size()){
      combo->append(profileNames->at(i));
      i++;
   }
}

void NewProjectController::on_cancel_clicked(){
   managerWindow->hide();
}

void NewProjectController::on_acept_clicked(){
   string temp = entry->get_text();
   string profile = combo->get_active_text();
   if(temp.length() == 0 || profile.length() == 0){
      Glib::ustring message("No se ingresó un nombre o perfil válido");
      Gtk::MessageDialog dialog("Error", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
      dialog.set_secondary_text(message);
      dialog.set_position(Gtk::WIN_POS_CENTER);
      dialog.run();
   }else{
      string path = "data/projects/";
      path = path + temp + ".gsmpj";
      ofstream myfile(path, std::ios_base::trunc);
      if(myfile.is_open()){
         Document d;
         d.SetObject();
         Value id;
         *NewProjectController::projectIdGenerator = *NewProjectController::projectIdGenerator + 1;
         id.SetInt(*NewProjectController::projectIdGenerator);
         Value name;
         name.SetString(temp.c_str(),temp.length(),d.GetAllocator());
         Value prof;
         prof.SetString(profile.c_str(),profile.length(),d.GetAllocator());
         Value generator;
         generator.SetInt(0);
         Value imageResumes;
         imageResumes.SetArray();

         d.AddMember("id", id, d.GetAllocator());
         d.AddMember("name", name, d.GetAllocator());
         d.AddMember("nameProfile", prof, d.GetAllocator());
         d.AddMember("idGenerator", generator, d.GetAllocator());
         d.AddMember("imageResumes", imageResumes, d.GetAllocator());

         projectNames->push_back(temp);
         mc->refreshProjects();
         StringBuffer buffer;
         Writer<StringBuffer> writer(buffer);
         d.Accept(writer);

         myfile << buffer.GetString();
         myfile.close();
         managerWindow->hide();
      }
   }
}

Gtk::Dialog* NewProjectController::getWindow(){
  return managerWindow;
}

NewProjectController::~NewProjectController(){

}

void NewProjectController::on_newProfile_clicked(){
   //managerWindow->hide();
   NewProfileController prfCtr(mc, this);
   prfCtr.getWindow()->run();
}