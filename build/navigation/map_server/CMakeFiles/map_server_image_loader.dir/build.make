# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/pf/rosWS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pf/rosWS/build

# Include any dependencies generated for this target.
include navigation/map_server/CMakeFiles/map_server_image_loader.dir/depend.make

# Include the progress variables for this target.
include navigation/map_server/CMakeFiles/map_server_image_loader.dir/progress.make

# Include the compile flags for this target's objects.
include navigation/map_server/CMakeFiles/map_server_image_loader.dir/flags.make

navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o: navigation/map_server/CMakeFiles/map_server_image_loader.dir/flags.make
navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o: /home/pf/rosWS/src/navigation/map_server/src/image_loader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pf/rosWS/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o"
	cd /home/pf/rosWS/build/navigation/map_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o -c /home/pf/rosWS/src/navigation/map_server/src/image_loader.cpp

navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.i"
	cd /home/pf/rosWS/build/navigation/map_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pf/rosWS/src/navigation/map_server/src/image_loader.cpp > CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.i

navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.s"
	cd /home/pf/rosWS/build/navigation/map_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pf/rosWS/src/navigation/map_server/src/image_loader.cpp -o CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.s

navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o.requires:
.PHONY : navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o.requires

navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o.provides: navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o.requires
	$(MAKE) -f navigation/map_server/CMakeFiles/map_server_image_loader.dir/build.make navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o.provides.build
.PHONY : navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o.provides

navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o.provides.build: navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o

# Object files for target map_server_image_loader
map_server_image_loader_OBJECTS = \
"CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o"

# External object files for target map_server_image_loader
map_server_image_loader_EXTERNAL_OBJECTS =

/home/pf/rosWS/devel/lib/libmap_server_image_loader.so: navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o
/home/pf/rosWS/devel/lib/libmap_server_image_loader.so: navigation/map_server/CMakeFiles/map_server_image_loader.dir/build.make
/home/pf/rosWS/devel/lib/libmap_server_image_loader.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/pf/rosWS/devel/lib/libmap_server_image_loader.so: navigation/map_server/CMakeFiles/map_server_image_loader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library /home/pf/rosWS/devel/lib/libmap_server_image_loader.so"
	cd /home/pf/rosWS/build/navigation/map_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/map_server_image_loader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
navigation/map_server/CMakeFiles/map_server_image_loader.dir/build: /home/pf/rosWS/devel/lib/libmap_server_image_loader.so
.PHONY : navigation/map_server/CMakeFiles/map_server_image_loader.dir/build

# Object files for target map_server_image_loader
map_server_image_loader_OBJECTS = \
"CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o"

# External object files for target map_server_image_loader
map_server_image_loader_EXTERNAL_OBJECTS =

navigation/map_server/CMakeFiles/CMakeRelink.dir/libmap_server_image_loader.so: navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o
navigation/map_server/CMakeFiles/CMakeRelink.dir/libmap_server_image_loader.so: navigation/map_server/CMakeFiles/map_server_image_loader.dir/build.make
navigation/map_server/CMakeFiles/CMakeRelink.dir/libmap_server_image_loader.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
navigation/map_server/CMakeFiles/CMakeRelink.dir/libmap_server_image_loader.so: navigation/map_server/CMakeFiles/map_server_image_loader.dir/relink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library CMakeFiles/CMakeRelink.dir/libmap_server_image_loader.so"
	cd /home/pf/rosWS/build/navigation/map_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/map_server_image_loader.dir/relink.txt --verbose=$(VERBOSE)

# Rule to relink during preinstall.
navigation/map_server/CMakeFiles/map_server_image_loader.dir/preinstall: navigation/map_server/CMakeFiles/CMakeRelink.dir/libmap_server_image_loader.so
.PHONY : navigation/map_server/CMakeFiles/map_server_image_loader.dir/preinstall

navigation/map_server/CMakeFiles/map_server_image_loader.dir/requires: navigation/map_server/CMakeFiles/map_server_image_loader.dir/src/image_loader.cpp.o.requires
.PHONY : navigation/map_server/CMakeFiles/map_server_image_loader.dir/requires

navigation/map_server/CMakeFiles/map_server_image_loader.dir/clean:
	cd /home/pf/rosWS/build/navigation/map_server && $(CMAKE_COMMAND) -P CMakeFiles/map_server_image_loader.dir/cmake_clean.cmake
.PHONY : navigation/map_server/CMakeFiles/map_server_image_loader.dir/clean

navigation/map_server/CMakeFiles/map_server_image_loader.dir/depend:
	cd /home/pf/rosWS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pf/rosWS/src /home/pf/rosWS/src/navigation/map_server /home/pf/rosWS/build /home/pf/rosWS/build/navigation/map_server /home/pf/rosWS/build/navigation/map_server/CMakeFiles/map_server_image_loader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : navigation/map_server/CMakeFiles/map_server_image_loader.dir/depend

