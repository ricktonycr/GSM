#include "../include/ImagesController.h"
#include <iostream>
//using namespace std;

ImagesController::ImagesController(string path){
   auto refBuilder = Gtk::Builder::create();
   try{
      refBuilder->add_from_file("src/view/images.glade");
   }catch(const Glib::FileError& ex){
      std::cerr << "FileError: " << ex.what() << std::endl;
   }
   refBuilder->get_widget("grid", ImagesController::imagesWindow);
   refBuilder->get_widget("nuevo", ImagesController::newButton);
   newButton->signal_clicked().connect( sigc::mem_fun(*this, &ImagesController::on_button_clicked) );
   imagesWindow->show_all_children();
   imagesWindow->show();
   cout << "asasaasasa" << endl;
}

void ImagesController::on_button_clicked(){
   Gtk::FileChooserDialog dialog("Please choose a file",Gtk::FILE_CHOOSER_ACTION_OPEN);
   dialog.set_transient_for(*imagesWindow);
   //Add response buttons the the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    /*Add filters, so that only certain file types can be selected:
    Glib::RefPtr filter_text = Gtk::FileFilter::create();
    filter_text->set_name("Text files");
    filter_text->add_mime_type("text/plain");
    dialog.add_filter(filter_text);

    Glib::RefPtr filter_cpp = Gtk::FileFilter::create();
    filter_cpp->set_name("C/C++ files");
    filter_cpp->add_mime_type("text/x-c");
    filter_cpp->add_mime_type("text/x-c++");
    filter_cpp->add_mime_type("text/x-c-header");
    dialog.add_filter(filter_cpp);

    Glib::RefPtr filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);*/

    //Show the dialog and wait for a user response:
    int result = dialog.run();

    //Handle the response:
    switch(result){
    case(Gtk::RESPONSE_OK):
    {
        // The user selected a file
        std::cout << "Open clicked." << std::endl;
        std::string filename = dialog.get_filename();
        std::cout << "File selected: " <<  filename << std::endl;
        break;
    }
    case(Gtk::RESPONSE_CANCEL):
    {
        // The user clicked cancel
        std::cout << "Cancel clicked." << std::endl;
        break;
    }
    default:
    {
        // The user closed the dialog box
        std::cout << "Unexpected button clicked." << std::endl;
        break;
    }
    }
}