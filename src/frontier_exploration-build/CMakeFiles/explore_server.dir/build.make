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
CMAKE_SOURCE_DIR = /home/pf/rosWS/src/frontier_exploration

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pf/rosWS/src/frontier_exploration-build

# Include any dependencies generated for this target.
include CMakeFiles/explore_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/explore_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/explore_server.dir/flags.make

CMakeFiles/explore_server.dir/src/explore_server.cpp.o: CMakeFiles/explore_server.dir/flags.make
CMakeFiles/explore_server.dir/src/explore_server.cpp.o: /home/pf/rosWS/src/frontier_exploration/src/explore_server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pf/rosWS/src/frontier_exploration-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/explore_server.dir/src/explore_server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/explore_server.dir/src/explore_server.cpp.o -c /home/pf/rosWS/src/frontier_exploration/src/explore_server.cpp

CMakeFiles/explore_server.dir/src/explore_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/explore_server.dir/src/explore_server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pf/rosWS/src/frontier_exploration/src/explore_server.cpp > CMakeFiles/explore_server.dir/src/explore_server.cpp.i

CMakeFiles/explore_server.dir/src/explore_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/explore_server.dir/src/explore_server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pf/rosWS/src/frontier_exploration/src/explore_server.cpp -o CMakeFiles/explore_server.dir/src/explore_server.cpp.s

CMakeFiles/explore_server.dir/src/explore_server.cpp.o.requires:
.PHONY : CMakeFiles/explore_server.dir/src/explore_server.cpp.o.requires

CMakeFiles/explore_server.dir/src/explore_server.cpp.o.provides: CMakeFiles/explore_server.dir/src/explore_server.cpp.o.requires
	$(MAKE) -f CMakeFiles/explore_server.dir/build.make CMakeFiles/explore_server.dir/src/explore_server.cpp.o.provides.build
.PHONY : CMakeFiles/explore_server.dir/src/explore_server.cpp.o.provides

CMakeFiles/explore_server.dir/src/explore_server.cpp.o.provides.build: CMakeFiles/explore_server.dir/src/explore_server.cpp.o

# Object files for target explore_server
explore_server_OBJECTS = \
"CMakeFiles/explore_server.dir/src/explore_server.cpp.o"

# External object files for target explore_server
explore_server_EXTERNAL_OBJECTS =

devel/lib/frontier_exploration/explore_server: CMakeFiles/explore_server.dir/src/explore_server.cpp.o
devel/lib/frontier_exploration/explore_server: CMakeFiles/explore_server.dir/build.make
devel/lib/frontier_exploration/explore_server: /home/pf/rosWS/devel/lib/libcostmap_2d.so
devel/lib/frontier_exploration/explore_server: /home/pf/rosWS/devel/lib/liblayers.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/liblaser_geometry.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libpcl_ros_filters.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libpcl_ros_io.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libpcl_ros_tf.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_common.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_octree.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_io.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_kdtree.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_search.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_sample_consensus.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_filters.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_features.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_keypoints.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_segmentation.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_visualization.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_outofcore.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_registration.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_recognition.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_surface.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_people.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_tracking.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libpcl_apps.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libqhull.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libOpenNI.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
devel/lib/frontier_exploration/explore_server: /usr/lib/libvtkCommon.so.5.8.0
devel/lib/frontier_exploration/explore_server: /usr/lib/libvtkRendering.so.5.8.0
devel/lib/frontier_exploration/explore_server: /usr/lib/libvtkHybrid.so.5.8.0
devel/lib/frontier_exploration/explore_server: /usr/lib/libvtkCharts.so.5.8.0
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libnodeletlib.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libbondcpp.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libuuid.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/librosbag.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/librosbag_storage.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libroslz4.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/liblz4.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libtopic_tools.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libtinyxml.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libclass_loader.so
devel/lib/frontier_exploration/explore_server: /usr/lib/libPocoFoundation.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libdl.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libroslib.so
devel/lib/frontier_exploration/explore_server: /home/pf/rosWS/devel/lib/libvoxel_grid.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libdynamic_reconfigure_config_init_mutex.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libtf.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libtf2_ros.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libmessage_filters.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libtf2.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libactionlib.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libroscpp.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libboost_signals.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/librosconsole.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/librosconsole_log4cxx.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/librosconsole_backend_interface.so
devel/lib/frontier_exploration/explore_server: /usr/lib/liblog4cxx.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libboost_regex.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libxmlrpcpp.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libroscpp_serialization.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/librostime.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
devel/lib/frontier_exploration/explore_server: /opt/ros/indigo/lib/libcpp_common.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libboost_system.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libboost_thread.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libpthread.so
devel/lib/frontier_exploration/explore_server: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
devel/lib/frontier_exploration/explore_server: CMakeFiles/explore_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable devel/lib/frontier_exploration/explore_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/explore_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/explore_server.dir/build: devel/lib/frontier_exploration/explore_server
.PHONY : CMakeFiles/explore_server.dir/build

CMakeFiles/explore_server.dir/requires: CMakeFiles/explore_server.dir/src/explore_server.cpp.o.requires
.PHONY : CMakeFiles/explore_server.dir/requires

CMakeFiles/explore_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/explore_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/explore_server.dir/clean

CMakeFiles/explore_server.dir/depend:
	cd /home/pf/rosWS/src/frontier_exploration-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pf/rosWS/src/frontier_exploration /home/pf/rosWS/src/frontier_exploration /home/pf/rosWS/src/frontier_exploration-build /home/pf/rosWS/src/frontier_exploration-build /home/pf/rosWS/src/frontier_exploration-build/CMakeFiles/explore_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/explore_server.dir/depend

