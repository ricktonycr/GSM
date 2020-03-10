#ifndef IMAGESCONTROLLER_H
#define IMAGESCONTROLLER_H

#include <gtkmm.h>
using namespace std;

class ImagesController {
   public:
      ImagesController(string path);
      Gtk::ApplicationWindow* imagesWindow;
   private:
      int a;
      Gtk::Button* newButton;
      void on_button_clicked();
};

#endif