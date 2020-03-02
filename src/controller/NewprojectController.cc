#include "../include/NewProjectController.h"
#include <iostream>

NewProjectController::NewProjectController(){
   auto refBuilder = Gtk::Builder::create();
   try{
      refBuilder->add_from_file("src/view/newProject.glade");
   }catch(const Glib::FileError& ex){
      std::cerr << "FileError: " << ex.what() << std::endl;
   }
   refBuilder->get_widget("GtkDialog", NewProjectController::managerWindow);
   refBuilder->get_widget("Cancelar", NewProjectController::cancelButton);
   NewProjectController::cancelButton->signal_clicked().connect( sigc::mem_fun(*this, &NewProjectController::on_button_clicked) );
}

void NewProjectController::on_button_clicked(){
  managerWindow->hide();
}

Gtk::Dialog* NewProjectController::getWindow(){
  return managerWindow;
}

NewProjectController::~NewProjectController(){

}