#ifndef NEWPROFILECONTROLLER_H
#define NEWPROFILECONTROLLER_H

#include <gtkmm.h>
#include "ManagerController.h"
#include "NewProjectController.h"
using namespace std;

class NewProfileController {
   public:
      NewProfileController(ManagerController* manager, NewProjectController* project);
      virtual ~NewProfileController();
      Gtk::Dialog* getWindow();
      void refreshCombo();
   private:
      Gtk::Dialog* managerWindow;
      Gtk::Button* cancelButton;
      Gtk::Button* aceptButton;
      Gtk::Button* newProfile;
      Gtk::Button* add;
      Gtk::Entry* nombre;
      Gtk::ComboBoxText* combo;
      vector<string>* projectNames;
      vector<string>* profileNames;
      int* projectIdGenerator;
      ManagerController* mc;
      NewProjectController* prj;
      Gtk::ListBox* items;
      std::vector<string> splitown(string s, string delimiter);
   protected:
      //Signal handlers:
      void on_cancel_clicked();
      void on_acept_clicked();
      void on_add_clicked();
};

#endif