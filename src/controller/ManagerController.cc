#include "../include/ManagerController.h"
#include "../include/NewProjectController.h"
#include <iostream>

ManagerController::ManagerController(Glib::RefPtr<Gtk::Application> app){
   ManagerController::app = app;
   auto refBuilder = Gtk::Builder::create();
   try{
      refBuilder->add_from_file("src/view/manager.glade");
   }catch(const Glib::FileError& ex){
      std::cerr << "FileError: " << ex.what() << std::endl;
   }
   refBuilder->get_widget("GtkApplicationWindow", ManagerController::managerWindow);
   managerWindow->show_all_children();
   refBuilder->get_widget("NewButton", ManagerController::newButton);
   ManagerController::newButton->signal_clicked().connect( sigc::mem_fun(*this, &ManagerController::on_button_clicked) );
   refBuilder->get_widget("Salir", ManagerController::exitButton);
   ManagerController::exitButton->signal_clicked().connect( sigc::mem_fun(*this, &ManagerController::on_exit_clicked) );
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