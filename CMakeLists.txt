cmake_minimum_required (VERSION 2.6)
project (GSM++)

set(CMAKE_CXX_STANDARD 11)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED COMPONENTS OpenGL EGL)
pkg_check_modules(EPOXY REQUIRED epoxy)
set(GL_LIBS OpenGL::OpenGL OpenGL::EGL ${EPOXY_LIBRARIES})

include_directories(${Epoxy_INCLUDE_DIRS})

pkg_check_modules(GTKMM gtkmm-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(
    ${GTKMM_INCLUDE_DIRS}  )
link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})


add_executable(GSM
    src/main.cc
    src/controller/ImagesController.cc
    src/controller/ManagerController.cc
    src/controller/NewProfileController.cc
    src/controller/NewprojectController.cc
    src/controller/PointsController.cc
    src/model/ImageResume.cc
    src/resources/resources.c
    src/include/ImageResume.h
    src/include/ImagesController.h
    src/include/ManagerController.h
    src/include/NewProfileController.h
    src/include/NewProjectController.h
    src/include/PointsController.h
)

# install css
INSTALL(FILES src/all.css DESTINATION all.css )

include_directories(
    src/include/
    src/include/json/
)

# Link the target to the GTK+ libraries
target_link_libraries(GSM 
    ${GTKMM_LIBRARIES}
    ${GL_LIBS} )

file(COPY src/view/
    DESTINATION src/view/)

