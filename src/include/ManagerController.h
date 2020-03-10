#ifndef MANAGERCONTROLLER_H
#define MANAGERCONTROLLER_H

#include <gtkmm.h>
using namespace std;

class ManagerController {
   public:
      ManagerController(Glib::RefPtr<Gtk::Application> app);
      virtual ~ManagerController();
      Gtk::ApplicationWindow* getWindow();
      int projectIdGenerator;
      vector<string> projectNames;
      vector<string> profileNames;
      Gtk::ApplicationWindow* managerWindow;
      void refreshProjects();
   private:
      Gtk::Button* newButton;
      Gtk::Button* exitButton;
      Gtk::ListBox* projectList;
      Glib::RefPtr<Gtk::Application> app;
      int numberOfProjects;
      string roleActive;
      string languageActive;
      void readDocument();
      void saveDocument();
      void selected(Gtk::ListBoxRow* lista, Glib::ustring path);
   protected:
      //Signal handlers:
      void on_button_clicked();
      void on_exit_clicked();
};

#endif