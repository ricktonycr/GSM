#ifndef MANAGERCONTROLLER_H
#define MANAGERCONTROLLER_H

#include <gtkmm.h>

class ManagerController{
   public:
      ManagerController(const Glib::RefPtr<Gtk::Application>& app);
      virtual ~ManagerController();
      int init();
   private:
      Gtk::ApplicationWindow* managerWindow;
      Glib::RefPtr<Gtk::Application> application;
};

#endif