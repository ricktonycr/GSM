#ifndef POINTSCONTROLLER_H
#define POINTSCONTROLLER_H

#include <gtkmm.h>
#include "../include/json/document.h"
#include "../include/json/writer.h"
#include "../include/json/stringbuffer.h"
#include <giomm/resource.h>
#include <epoxy/gl.h>
using namespace std;

class PointsController{
    public:
        PointsController(int idProject, int id);
        virtual ~PointsController();
        Gtk::ApplicationWindow* pointsWindow;
    private:
        int idProject;
        Gtk::GLArea* canvas;
        int id;
        void realize();
        void unrealize();
        void init_buffers();
        void init_shaders();
        bool render(const Glib::RefPtr<Gdk::GLContext>&);
        protected: GLuint m_Vao {0};
        GLuint m_Program {0};
        GLuint m_Buffer {0};
        GLfloat* vertex_data;
};

#endif