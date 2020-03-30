#include "../include/PointsController.h"
#include <gdkmm/pixbuf.h>
#include <iostream>
#include <fstream>
using namespace std;
using namespace rapidjson;

enum {
   X_AXIS,
   Y_AXIS,
   Z_AXIS,
   N_AXIS
};

PointsController::PointsController(int idProject, int id):m_RotationAngles(N_AXIS, 0.0f){
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
      refBuilder->add_from_file("../src/view/points.glade");
   }
   catch (const Glib::FileError &ex){
      std::cerr << "FileError: " << ex.what() << std::endl;
   }
   cout << "Por aqui" << endl;
   refBuilder->get_widget("Points", PointsController::pointsWindow);
   refBuilder->get_widget("Canvas", PointsController::canvas);
   refBuilder->get_widget("toolbar", PointsController::toolbar);
   canvas->set_hexpand(true);
   canvas->set_vexpand(true);
   canvas->set_auto_render(true);

   canvas->signal_realize().connect(sigc::mem_fun(*this, &PointsController::realize));
   // Important that the unrealize signal calls our handler to clean up
   // GL resources _before_ the default unrealize handler is called (the "false")
   canvas->signal_unrealize().connect(sigc::mem_fun(*this, &PointsController::unrealize), false);
   canvas->signal_render().connect(sigc::mem_fun(*this, &PointsController::render));
   toolbar->set_toolbar_style(Gtk::TOOLBAR_ICONS);
  
   Glib::RefPtr<Gtk::Action> act = Gtk::Action::create("new", Gtk::Stock::NEW, "", "Create New Window");
   Glib::RefPtr< Gtk::ActionGroup > actGrp = Gtk::ActionGroup::create ("MainGroup");
   actGrp->add (act, Gtk::AccelKey ("<control>N"), sigc::mem_fun(*this, &PointsController::actions_handler));
   Gtk::ToolItem* item = act->create_tool_item ();
   item->set_tooltip_text("Create New Window" );
   item->set_expand (false);
   item->set_homogeneous (false);
   item->set_size_request(20,20);
   toolbar->append(*item);
   toolbar->show_all();
   pointsWindow->show_all();
}

PointsController::~PointsController(){
}

void PointsController::realize(){
   cout << "realize" << endl;
   canvas->make_current();
   try{
      canvas->throw_if_error();
      cout << "antes" << endl;
      init_buffers();
      init_shaders();
      cout << "despues" << endl;
   }catch(const Gdk::GLError& gle){
      cerr << "An error occured making the context current during realize:" << endl;
      cerr << gle.domain() << "-" << gle.code() << "-" << gle.what() << endl;
   }
}

void PointsController::unrealize(){
   cout << "unrealize" << endl;
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
   cout << "render" << endl;
   toolbar->queue_draw();
   try{
      cout << "antes de " << endl;
      m_RotationAngles[0] = m_RotationAngles[0] + 0.02;
      //canvas->throw_if_error();
      glClearColor(0.5, 0.5, 0.5, 1.0);
      glClear(GL_COLOR_BUFFER_BIT);
      draw_triangle();
      glFlush();
         cout << "despues de " << endl;
      return true;
   }catch(const Gdk::GLError& gle){
      cout << "An error occurred in the render callback of the GLArea" << endl;
      cout << gle.domain() << "-" << gle.code() << "-" << gle.what() << endl;
      return false;
   }
}

void PointsController::init_buffers(){
   cout << "init buffers" << endl;
   glGenVertexArrays(1, &m_Vao);
   glBindVertexArray(m_Vao);
   glGenBuffers(1, &m_Buffer);
   glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);
   glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void PointsController::init_shaders(){
   cout << "init shaders" << endl;
   auto vshader_bytes = Gio::Resource::lookup_data_global("/glarea/glarea-vertex.glsl");
   if(!vshader_bytes){
      cerr << "Failed fetching vertex shader resource" << endl;
      m_Program = 0;
      return;
   }
   gsize vshader_size {vshader_bytes->get_size()};
   auto vertex = create_shader(GL_VERTEX_SHADER, (const char*)vshader_bytes->get_data(vshader_size));
   if(vertex == 0){
      m_Program = 0;
      return;
   }
   auto fshader_bytes = Gio::Resource::lookup_data_global("/glarea/glarea-fragment.glsl");
   if(!fshader_bytes){
      cerr << "Failed fetching fragment shader resource" << endl;
      glDeleteShader(vertex);
      m_Program = 0;
      return;
   }
   gsize fshader_size {fshader_bytes->get_size()};
   auto fragment = create_shader(GL_FRAGMENT_SHADER,(const char*)fshader_bytes->get_data(fshader_size));
   if(fragment == 0){
      glDeleteShader(vertex);
      m_Program = 0;
      return;
   }
   m_Program = glCreateProgram();
   glAttachShader(m_Program, vertex);
   glAttachShader(m_Program, fragment); 
   glLinkProgram(m_Program); 
   int status;
   glGetProgramiv(m_Program, GL_LINK_STATUS, &status);
   if(status == GL_FALSE){
      int log_len;
      glGetProgramiv(m_Program, GL_INFO_LOG_LENGTH, &log_len);
      string log_space(log_len+1, ' ');
      glGetProgramInfoLog(m_Program, log_len, nullptr, (GLchar*)log_space.c_str());
      cerr << "Linking failure: " << log_space << endl;
      glDeleteProgram(m_Program);
      m_Program = 0;
   }else{
      /* Get the location of the "mvp" uniform */
      m_Mvp = glGetUniformLocation(m_Program, "mvp");
      glDetachShader(m_Program, vertex);
      glDetachShader(m_Program, fragment);
   }
   glDeleteShader(vertex);
   glDeleteShader(fragment);
}

void PointsController::actions_handler(){
   cout << "hola " << endl;
   canvas->queue_render();
}

GLuint PointsController::create_shader(int type, const char *src){
   cout << "create shader" << endl;
   auto shader = glCreateShader(type);
   glShaderSource(shader, 1, &src, nullptr);
   glCompileShader(shader);
   int status;
   glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
   if(status == GL_FALSE){
      int log_len;
      glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_len);
      string log_space(log_len+1, ' ');
      glGetShaderInfoLog(shader, log_len, nullptr, (GLchar*)log_space.c_str());
      cerr << "Compile failure in " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader: " << log_space << endl;
      glDeleteShader(shader);
      return 0;
   }
   cout << "shader creado" << src << endl;
   return shader;
}

void PointsController::draw_triangle(){
   cout << "draw triangle" << endl;
   float mvp[16];
   compute_mvp(mvp,
      m_RotationAngles[X_AXIS],
      m_RotationAngles[Y_AXIS],
      m_RotationAngles[Z_AXIS]);
   glUseProgram(m_Program);
   glUniformMatrix4fv(m_Mvp, 1, GL_FALSE, &mvp[0]);
   glBindBuffer(GL_ARRAY_BUFFER, m_Vao);
   glEnableVertexAttribArray(0);
   glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
   glDrawArrays(GL_TRIANGLES, 0, 3);
   glDisableVertexAttribArray(0);
   glBindBuffer(GL_ARRAY_BUFFER, 0);
   glUseProgram(0);
}

void PointsController::compute_mvp(float *res, float phi, float theta, float psi){
   cout << "compute mvp" << endl;
   float x       {phi * ((float)G_PI / 180.f)};
   float y       {theta * ((float)G_PI / 180.f)};
   float z       {psi * ((float)G_PI / 180.f)};
   float c1      {cosf (x)};
   float s1      {sinf (x)};
   float c2      {cosf (y)};
   float s2      {sinf (y)};
   float c3      {cosf (z)};
   float s3      {sinf (z)};
   float c3c2    {c3 * c2};
   float s3c1    {s3 * c1};
   float c3s2s1  {c3 * s2 * s1};
   float s3s1    {s3 * s1};
   float c3s2c1  {c3 * s2 * c1};
   float s3c2    {s3 * c2};
   float c3c1    {c3 * c1};
   float s3s2s1  {s3 * s2 * s1};
   float c3s1    {c3 * s1};
   float s3s2c1  {s3 * s2 * c1};
   float c2s1    {c2 * s1};
   float c2c1    {c2 * c1};
   /* apply all three rotations using the three matrices:
   *
   * ⎡  c3 s3 0 ⎤ ⎡ c2  0 -s2 ⎤ ⎡ 1   0  0 ⎤
   * ⎢ -s3 c3 0 ⎥ ⎢  0  1   0 ⎥ ⎢ 0  c1 s1 ⎥
   * ⎣   0  0 1 ⎦ ⎣ s2  0  c2 ⎦ ⎣ 0 -s1 c1 ⎦
   */
   res[0] = c3c2;  res[4] = s3c1 + c3s2s1;  res[8] = s3s1 - c3s2c1; res[12] = 0.f;
   res[1] = -s3c2; res[5] = c3c1 - s3s2s1;  res[9] = c3s1 + s3s2c1; res[13] = 0.f;
   res[2] = s2;    res[6] = -c2s1;         res[10] = c2c1;          res[14] = 0.f;
   res[3] = 0.f;   res[7] = 0.f;           res[11] = 0.f;           res[15] = 1.f;
}