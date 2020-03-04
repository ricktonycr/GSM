#ifndef MANAGERCONTROLLER_H
#define MANAGERCONTROLLER_H

#include <gtkmm.h>
using namespace std;

class ManagerController {
   public:
      ManagerController(Glib::RefPtr<Gtk::Application> app);
      virtual ~ManagerController();
      Gtk::ApplicationWindow* getWindow();
   private:
      Gtk::Button* newButton;
      Gtk::Button* exitButton;
      Gtk::ListBox* projectList;
      Gtk::ApplicationWindow* managerWindow;
      Glib::RefPtr<Gtk::Application> app;
      int numberOfProjects;
      string roleActive;
      string languageActive;
      int projectIdGenerator;
      vector<string> projectNames;
      vector<string> projectPaths;
      void readDocument();
      void saveDocument();
      void selected(Glib::ustring path);
   protected:
      //Signal handlers:
      void on_button_clicked();
      void on_exit_clicked();
};

#endif