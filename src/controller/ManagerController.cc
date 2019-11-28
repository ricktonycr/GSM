#include "../include/ManagerController.h"
#include <iostream>

ManagerController::ManagerController(const Glib::RefPtr<Gtk::Application>& app){
   ManagerController::application = app;
   auto refBuilder = Gtk::Builder::create();
   try{
      refBuilder->add_from_file("src/view/manager.glade");
   }catch(const Glib::FileError& ex){
      std::cerr << "FileError: " << ex.what() << std::endl;
   }
   refBuilder->get_widget("GtkApplicationWindow", ManagerController::managerWindow);
}

int ManagerController::init(){
   return application->run(*ManagerController::managerWindow);
}

ManagerController::~ManagerController(){

}