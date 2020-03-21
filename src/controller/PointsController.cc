#include "../include/PointsController.h"
#include <gdkmm/pixbuf.h>
#include <iostream>
#include <fstream>
#include "../include/json/document.h"
#include "../include/json/writer.h"
#include "../include/json/stringbuffer.h"
using namespace std;
using namespace rapidjson;

PointsController::PointsController(int idProject, int id){
   PointsController::idProject = idProject;
   PointsController::id = id;
   auto refBuilder = Gtk::Builder::create();
   try{
      refBuilder->add_from_file("src/view/points.glade");
   }
   catch (const Glib::FileError &ex){
      std::cerr << "FileError: " << ex.what() << std::endl;
   }
   refBuilder->get_widget("Points", PointsController::pointsWindow);
   pointsWindow->show_all_children();
   pointsWindow->show();
}

PointsController::~PointsController(){
}