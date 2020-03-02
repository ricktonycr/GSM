#ifndef NEWPROJECTCONTROLLER_H
#define NEWPROJECTCONTROLLER_H

#include <gtkmm.h>

class NewProjectController {
   public:
      NewProjectController();
      virtual ~NewProjectController();
      Gtk::Dialog* getWindow();
   private:
      Gtk::Dialog* managerWindow;
      Gtk::Button* cancelButton;
   protected:
      //Signal handlers:
      void on_button_clicked();
};

#endif