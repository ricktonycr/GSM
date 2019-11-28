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
#include "include/SplashController.h"
#include "include/ManagerController.h"
#include <iostream>

Gtk::ApplicationWindow* w = nullptr;

int main(int argc, char *argv[]){
   auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
   SplashController splashController(app);
   splashController.init();

   app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

   ManagerController manager(app);
   manager.init();

   std::cout << "prueba" << std::endl;
}