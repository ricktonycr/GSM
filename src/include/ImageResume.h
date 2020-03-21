#ifndef IMAGERESUME_H
#define IMAGERESUME_H

#include <gtkmm.h>
using namespace std;

class ImageResume : Gtk::Image {
    public:
        ImageResume() : Gtk::Image(){};
        ImageResume(const Glib::RefPtr<Gdk::Pixbuf> &pixbuf) : Gtk::Image(pixbuf){};
        virtual ~ImageResume();
        int id;
        string iconURL;
        string name;
        string state;
        void set_manage() { Gtk::Image::set_manage(); }
};

#endif