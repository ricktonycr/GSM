#ifndef IMAGESCONTROLLER_H
#define IMAGESCONTROLLER_H

#include <gtkmm.h>
using namespace std;

class ImagesController {
   public:
      ImagesController(string path,Glib::RefPtr<Gtk::Application> app);
      Gtk::ApplicationWindow* imagesWindow;
   private:
      int a;
      int id;
      int idGenerator;
      string name;
      string profile;
      Gtk::Button* newButton;
      Gtk::FlowBox* flow;
      Gtk::Button* eliminar;
      Gtk::Button* cerrar;
      Gtk::Button* editar;
      void on_button_clicked();
      void on_delete_clicked();
      void on_hide_clicked();
      void readDocument();
      void writeDocument();
      void on_close_clicked();
      void on_edit_clicked();
      string completePath;
      Glib::RefPtr<Gtk::Application> app;
};

#endif