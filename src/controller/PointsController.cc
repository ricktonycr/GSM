#include "../include/PointsController.h"
#include <gdkmm/pixbuf.h>
#include <iostream>
#include <fstream>
using namespace std;
using namespace rapidjson;

PointsController::PointsController(int idProject, int id){
   PointsController::idProject = idProject;
   PointsController::id = id;
   GLfloat v[] = {
      0.f,   0.5f,   0.f, 1.f,
      0.5f, -0.366f, 0.f, 1.f,
      -0.5f, -0.366f, 0.f, 1.f,
   };

   vertex_data = v;
   auto refBuilder = Gtk::Builder::create();
   try{
      refBuilder->add_from_file("src/view/points.glade");
   }
   catch (const Glib::FileError &ex){
      std::cerr << "FileError: " << ex.what() << std::endl;
   }
   cout << "Por aqui" << endl;
   refBuilder->get_widget("Points", PointsController::pointsWindow);
   refBuilder->get_widget("Canvas", PointsController::canvas);
   canvas->set_hexpand(true);
   canvas->set_vexpand(true);
   canvas->set_auto_render(true);

   // Connect gl area signals
   canvas->signal_realize().connect(sigc::mem_fun(*this, &PointsController::realize));
   // Important that the unrealize signal calls our handler to clean up
   // GL resources _before_ the default unrealize handler is called (the "false")
   canvas->signal_unrealize().connect(sigc::mem_fun(*this, &PointsController::unrealize), false);
   canvas->signal_render().connect(sigc::mem_fun(*this, &PointsController::render));
   pointsWindow->show_all_children();
   pointsWindow->show();
}

PointsController::~PointsController(){
}

void PointsController::realize(){
   canvas->make_current();
   try{
      canvas->throw_if_error();
      init_buffers();
      init_shaders();
   }catch(const Gdk::GLError& gle){
      cerr << "An error occured making the context current during realize:" << endl;
      cerr << gle.domain() << "-" << gle.code() << "-" << gle.what() << endl;
   }
}

void PointsController::unrealize(){
   canvas->make_current();
   try{
      canvas->throw_if_error();
      // Delete buffers and program
      glDeleteBuffers(1, &m_Vao);
      glDeleteProgram(m_Program);
   }catch(const Gdk::GLError& gle){
      cerr << "An error occured making the context current during unrealize" << endl;
      cerr << gle.domain() << "-" << gle.code() << "-" << gle.what() << endl;
   }
}

bool PointsController::render(const Glib::RefPtr<Gdk::GLContext>&){
}

void PointsController::init_buffers(){
      cout << "antes" << endl;
   glGenVertexArrays(1, &m_Vao);
      cout << "despues" << endl;
   glBindVertexArray(m_Vao);
   glGenBuffers(1, &m_Buffer);
   glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);
   glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void PointsController::init_shaders(){
   
}