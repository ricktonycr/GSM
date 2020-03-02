#ifndef MANAGERCONTROLLER_H
#define MANAGERCONTROLLER_H

#include <gtkmm.h>

class ManagerController {
   public:
      ManagerController(Glib::RefPtr<Gtk::Application> app);
      virtual ~ManagerController();
      Gtk::ApplicationWindow* getWindow();
   private:
      Gtk::Button* newButton;
      Gtk::Button* exitButton;
      Gtk::ApplicationWindow* managerWindow;
      Glib::RefPtr<Gtk::Application> app;
   protected:
      //Signal handlers:
      void on_button_clicked();
      void on_exit_clicked();
};

#endif