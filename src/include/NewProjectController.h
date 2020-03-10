#ifndef NEWPROJECTCONTROLLER_H
#define NEWPROJECTCONTROLLER_H

#include <gtkmm.h>
#include "ManagerController.h"
using namespace std;

class NewProjectController {
   public:
      NewProjectController(ManagerController* manager);
      virtual ~NewProjectController();
      Gtk::Dialog* getWindow();
   private:
      Gtk::Dialog* managerWindow;
      Gtk::Button* cancelButton;
      Gtk::Button* aceptButton;
      Gtk::Button* newProfile;
      Gtk::Entry* entry;
      Gtk::ComboBoxText* combo;
      vector<string>* projectNames;
      vector<string>* profileNames;
      int* projectIdGenerator;
      ManagerController* mc;
   protected:
      //Signal handlers:
      void on_cancel_clicked();
      void on_acept_clicked();
      void on_newProfile_clicked();
};

#endif