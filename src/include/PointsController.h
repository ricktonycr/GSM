#ifndef POINTSCONTROLLER_H
#define POINTSCONTROLLER_H

#include <gtkmm.h>
using namespace std;

class PointsController{
    public:
        PointsController(int idProject, int id);
        virtual ~PointsController();
        Gtk::ApplicationWindow* pointsWindow;
    private:
        int idProject;
        int id;
};

#endif