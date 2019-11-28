#include "../include/SplashController.h"
#include <iostream>

SplashController::SplashController(const Glib::RefPtr<Gtk::Application>& app){
   application = app;
   auto refBuilder = Gtk::Builder::create();
   try{
      refBuilder->add_from_file("src/view/splash.glade");
   }catch(const Glib::FileError& ex){
      std::cerr << "FileError: " << ex.what() << std::endl;
   }
   refBuilder->get_widget("GtkApplicationWindow", SplashController::splashWindow);

   //Shows the window and returns when it is closed.
   //app->run(*SplashController::splashWindow);
}

int SplashController::init(){
   return application->run(*SplashController::splashWindow);
}

SplashController::~SplashController(){

}