# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rcruzr/workspace/citesoft/GSM++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rcruzr/workspace/citesoft/GSM++/build

# Include any dependencies generated for this target.
include CMakeFiles/GSM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GSM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GSM.dir/flags.make

CMakeFiles/GSM.dir/src/main.cc.o: CMakeFiles/GSM.dir/flags.make
CMakeFiles/GSM.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rcruzr/workspace/citesoft/GSM++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GSM.dir/src/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GSM.dir/src/main.cc.o -c /home/rcruzr/workspace/citesoft/GSM++/src/main.cc

CMakeFiles/GSM.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GSM.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rcruzr/workspace/citesoft/GSM++/src/main.cc > CMakeFiles/GSM.dir/src/main.cc.i

CMakeFiles/GSM.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GSM.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rcruzr/workspace/citesoft/GSM++/src/main.cc -o CMakeFiles/GSM.dir/src/main.cc.s

CMakeFiles/GSM.dir/src/controller/ImagesController.cc.o: CMakeFiles/GSM.dir/flags.make
CMakeFiles/GSM.dir/src/controller/ImagesController.cc.o: ../src/controller/ImagesController.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rcruzr/workspace/citesoft/GSM++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GSM.dir/src/controller/ImagesController.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GSM.dir/src/controller/ImagesController.cc.o -c /home/rcruzr/workspace/citesoft/GSM++/src/controller/ImagesController.cc

CMakeFiles/GSM.dir/src/controller/ImagesController.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GSM.dir/src/controller/ImagesController.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rcruzr/workspace/citesoft/GSM++/src/controller/ImagesController.cc > CMakeFiles/GSM.dir/src/controller/ImagesController.cc.i

CMakeFiles/GSM.dir/src/controller/ImagesController.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GSM.dir/src/controller/ImagesController.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rcruzr/workspace/citesoft/GSM++/src/controller/ImagesController.cc -o CMakeFiles/GSM.dir/src/controller/ImagesController.cc.s

CMakeFiles/GSM.dir/src/controller/ManagerController.cc.o: CMakeFiles/GSM.dir/flags.make
CMakeFiles/GSM.dir/src/controller/ManagerController.cc.o: ../src/controller/ManagerController.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rcruzr/workspace/citesoft/GSM++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GSM.dir/src/controller/ManagerController.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GSM.dir/src/controller/ManagerController.cc.o -c /home/rcruzr/workspace/citesoft/GSM++/src/controller/ManagerController.cc

CMakeFiles/GSM.dir/src/controller/ManagerController.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GSM.dir/src/controller/ManagerController.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rcruzr/workspace/citesoft/GSM++/src/controller/ManagerController.cc > CMakeFiles/GSM.dir/src/controller/ManagerController.cc.i

CMakeFiles/GSM.dir/src/controller/ManagerController.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GSM.dir/src/controller/ManagerController.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rcruzr/workspace/citesoft/GSM++/src/controller/ManagerController.cc -o CMakeFiles/GSM.dir/src/controller/ManagerController.cc.s

CMakeFiles/GSM.dir/src/controller/NewProfileController.cc.o: CMakeFiles/GSM.dir/flags.make
CMakeFiles/GSM.dir/src/controller/NewProfileController.cc.o: ../src/controller/NewProfileController.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rcruzr/workspace/citesoft/GSM++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GSM.dir/src/controller/NewProfileController.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GSM.dir/src/controller/NewProfileController.cc.o -c /home/rcruzr/workspace/citesoft/GSM++/src/controller/NewProfileController.cc

CMakeFiles/GSM.dir/src/controller/NewProfileController.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GSM.dir/src/controller/NewProfileController.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rcruzr/workspace/citesoft/GSM++/src/controller/NewProfileController.cc > CMakeFiles/GSM.dir/src/controller/NewProfileController.cc.i

CMakeFiles/GSM.dir/src/controller/NewProfileController.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GSM.dir/src/controller/NewProfileController.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rcruzr/workspace/citesoft/GSM++/src/controller/NewProfileController.cc -o CMakeFiles/GSM.dir/src/controller/NewProfileController.cc.s

CMakeFiles/GSM.dir/src/controller/NewprojectController.cc.o: CMakeFiles/GSM.dir/flags.make
CMakeFiles/GSM.dir/src/controller/NewprojectController.cc.o: ../src/controller/NewprojectController.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rcruzr/workspace/citesoft/GSM++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GSM.dir/src/controller/NewprojectController.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GSM.dir/src/controller/NewprojectController.cc.o -c /home/rcruzr/workspace/citesoft/GSM++/src/controller/NewprojectController.cc

CMakeFiles/GSM.dir/src/controller/NewprojectController.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GSM.dir/src/controller/NewprojectController.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rcruzr/workspace/citesoft/GSM++/src/controller/NewprojectController.cc > CMakeFiles/GSM.dir/src/controller/NewprojectController.cc.i

CMakeFiles/GSM.dir/src/controller/NewprojectController.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GSM.dir/src/controller/NewprojectController.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rcruzr/workspace/citesoft/GSM++/src/controller/NewprojectController.cc -o CMakeFiles/GSM.dir/src/controller/NewprojectController.cc.s

CMakeFiles/GSM.dir/src/controller/PointsController.cc.o: CMakeFiles/GSM.dir/flags.make
CMakeFiles/GSM.dir/src/controller/PointsController.cc.o: ../src/controller/PointsController.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rcruzr/workspace/citesoft/GSM++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/GSM.dir/src/controller/PointsController.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GSM.dir/src/controller/PointsController.cc.o -c /home/rcruzr/workspace/citesoft/GSM++/src/controller/PointsController.cc

CMakeFiles/GSM.dir/src/controller/PointsController.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GSM.dir/src/controller/PointsController.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rcruzr/workspace/citesoft/GSM++/src/controller/PointsController.cc > CMakeFiles/GSM.dir/src/controller/PointsController.cc.i

CMakeFiles/GSM.dir/src/controller/PointsController.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GSM.dir/src/controller/PointsController.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rcruzr/workspace/citesoft/GSM++/src/controller/PointsController.cc -o CMakeFiles/GSM.dir/src/controller/PointsController.cc.s

CMakeFiles/GSM.dir/src/controller/glarea.cc.o: CMakeFiles/GSM.dir/flags.make
CMakeFiles/GSM.dir/src/controller/glarea.cc.o: ../src/controller/glarea.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rcruzr/workspace/citesoft/GSM++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/GSM.dir/src/controller/glarea.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GSM.dir/src/controller/glarea.cc.o -c /home/rcruzr/workspace/citesoft/GSM++/src/controller/glarea.cc

CMakeFiles/GSM.dir/src/controller/glarea.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GSM.dir/src/controller/glarea.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rcruzr/workspace/citesoft/GSM++/src/controller/glarea.cc > CMakeFiles/GSM.dir/src/controller/glarea.cc.i

CMakeFiles/GSM.dir/src/controller/glarea.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GSM.dir/src/controller/glarea.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rcruzr/workspace/citesoft/GSM++/src/controller/glarea.cc -o CMakeFiles/GSM.dir/src/controller/glarea.cc.s

CMakeFiles/GSM.dir/src/model/ImageResume.cc.o: CMakeFiles/GSM.dir/flags.make
CMakeFiles/GSM.dir/src/model/ImageResume.cc.o: ../src/model/ImageResume.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rcruzr/workspace/citesoft/GSM++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/GSM.dir/src/model/ImageResume.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GSM.dir/src/model/ImageResume.cc.o -c /home/rcruzr/workspace/citesoft/GSM++/src/model/ImageResume.cc

CMakeFiles/GSM.dir/src/model/ImageResume.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GSM.dir/src/model/ImageResume.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rcruzr/workspace/citesoft/GSM++/src/model/ImageResume.cc > CMakeFiles/GSM.dir/src/model/ImageResume.cc.i

CMakeFiles/GSM.dir/src/model/ImageResume.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GSM.dir/src/model/ImageResume.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rcruzr/workspace/citesoft/GSM++/src/model/ImageResume.cc -o CMakeFiles/GSM.dir/src/model/ImageResume.cc.s

CMakeFiles/GSM.dir/src/resources/resources.c.o: CMakeFiles/GSM.dir/flags.make
CMakeFiles/GSM.dir/src/resources/resources.c.o: ../src/resources/resources.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rcruzr/workspace/citesoft/GSM++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/GSM.dir/src/resources/resources.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/GSM.dir/src/resources/resources.c.o   -c /home/rcruzr/workspace/citesoft/GSM++/src/resources/resources.c

CMakeFiles/GSM.dir/src/resources/resources.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GSM.dir/src/resources/resources.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rcruzr/workspace/citesoft/GSM++/src/resources/resources.c > CMakeFiles/GSM.dir/src/resources/resources.c.i

CMakeFiles/GSM.dir/src/resources/resources.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GSM.dir/src/resources/resources.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rcruzr/workspace/citesoft/GSM++/src/resources/resources.c -o CMakeFiles/GSM.dir/src/resources/resources.c.s

# Object files for target GSM
GSM_OBJECTS = \
"CMakeFiles/GSM.dir/src/main.cc.o" \
"CMakeFiles/GSM.dir/src/controller/ImagesController.cc.o" \
"CMakeFiles/GSM.dir/src/controller/ManagerController.cc.o" \
"CMakeFiles/GSM.dir/src/controller/NewProfileController.cc.o" \
"CMakeFiles/GSM.dir/src/controller/NewprojectController.cc.o" \
"CMakeFiles/GSM.dir/src/controller/PointsController.cc.o" \
"CMakeFiles/GSM.dir/src/controller/glarea.cc.o" \
"CMakeFiles/GSM.dir/src/model/ImageResume.cc.o" \
"CMakeFiles/GSM.dir/src/resources/resources.c.o"

# External object files for target GSM
GSM_EXTERNAL_OBJECTS =

GSM: CMakeFiles/GSM.dir/src/main.cc.o
GSM: CMakeFiles/GSM.dir/src/controller/ImagesController.cc.o
GSM: CMakeFiles/GSM.dir/src/controller/ManagerController.cc.o
GSM: CMakeFiles/GSM.dir/src/controller/NewProfileController.cc.o
GSM: CMakeFiles/GSM.dir/src/controller/NewprojectController.cc.o
GSM: CMakeFiles/GSM.dir/src/controller/PointsController.cc.o
GSM: CMakeFiles/GSM.dir/src/controller/glarea.cc.o
GSM: CMakeFiles/GSM.dir/src/model/ImageResume.cc.o
GSM: CMakeFiles/GSM.dir/src/resources/resources.c.o
GSM: CMakeFiles/GSM.dir/build.make
GSM: /usr/lib/libOpenGL.so
GSM: /usr/lib/libEGL.so
GSM: /usr/lib/libOpenGL.so
GSM: CMakeFiles/GSM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rcruzr/workspace/citesoft/GSM++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable GSM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GSM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GSM.dir/build: GSM

.PHONY : CMakeFiles/GSM.dir/build

CMakeFiles/GSM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GSM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GSM.dir/clean

CMakeFiles/GSM.dir/depend:
	cd /home/rcruzr/workspace/citesoft/GSM++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rcruzr/workspace/citesoft/GSM++ /home/rcruzr/workspace/citesoft/GSM++ /home/rcruzr/workspace/citesoft/GSM++/build /home/rcruzr/workspace/citesoft/GSM++/build /home/rcruzr/workspace/citesoft/GSM++/build/CMakeFiles/GSM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GSM.dir/depend

