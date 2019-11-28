#ifndef SPLASHCONTROLLER_H
#define SPLASHCONTROLLER_H

#include <gtkmm.h>

class SplashController {
   public:
      SplashController(const Glib::RefPtr<Gtk::Application>& app);
      virtual ~SplashController();
      int init();
   private:
      Gtk::ApplicationWindow* splashWindow;
      Glib::RefPtr<Gtk::Application> application;
};

#endif