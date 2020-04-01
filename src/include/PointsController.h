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
        Gtk::Window* pointsWindow;
        int idProject;
        Gtk::GLArea canvas;
        Gtk::Toolbar* toolbar;
        int id;
        void realize();
        void unrealize();
        void init_buffers();
        void init_shaders();
        bool render(const Glib::RefPtr<Gdk::GLContext>&);
        GLuint m_Vao {0};
        GLuint m_Program {0};
        GLuint m_Buffer {0};
        void actions_handler();
        GLuint create_shader(int type, const char *src);
        GLuint m_Mvp {0};
        void draw_triangle();
        void compute_mvp(float *res,float phi,float theta,float psi);
        std::vector<float> m_RotationAngles;
        Gtk::Box* box;
};

#endif