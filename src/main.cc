/* gtkmm example Copyright (C) 2002 gtkmm development team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <gtkmm.h>
#include <gtkmm-3.0/gtkmm.h>
#include <gtkmm/cssprovider.h>
#include "include/ManagerController.h"
#include <gtkmm/cssprovider.h>
#include <gtk/gtk.h>
#include <iostream>
#include <fstream>
using namespace std;

Gtk::ApplicationWindow* w = nullptr;

int main(int argc, char *argv[]){

   auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

   std::string css_relpath = "src/view/all.css";
   Glib::RefPtr<Gtk::CssProvider> cssProvider = Gtk::CssProvider::create();
   cssProvider->load_from_path("src/view/all.css");
   Glib::RefPtr<Gtk::StyleContext> styleContext = Gtk::StyleContext::create();

   Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
   styleContext->add_provider_for_screen(screen, cssProvider, 600);

   ManagerController manager(app);

   return app->run(*manager.getWindow());
}