# CMake generated Testfile for 
# Source directory: /home/pf/rosWS/src/frontier_exploration
# Build directory: /home/pf/rosWS/src/frontier_exploration-build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(_ctest_frontier_exploration_gtest_frontier_search_tests "/home/pf/rosWS/src/frontier_exploration-build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/pf/rosWS/src/frontier_exploration-build/test_results/frontier_exploration/gtest-frontier_search_tests.xml" "--return-code" "/home/pf/rosWS/src/frontier_exploration-build/devel/lib/frontier_exploration/frontier_search_tests --gtest_output=xml:/home/pf/rosWS/src/frontier_exploration-build/test_results/frontier_exploration/gtest-frontier_search_tests.xml")
ADD_TEST(_ctest_frontier_exploration_gtest_geometry_tools_tests "/home/pf/rosWS/src/frontier_exploration-build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/pf/rosWS/src/frontier_exploration-build/test_results/frontier_exploration/gtest-geometry_tools_tests.xml" "--return-code" "/home/pf/rosWS/src/frontier_exploration-build/devel/lib/frontier_exploration/geometry_tools_tests --gtest_output=xml:/home/pf/rosWS/src/frontier_exploration-build/test_results/frontier_exploration/gtest-geometry_tools_tests.xml")
ADD_TEST(_ctest_frontier_exploration_gtest_costmap_tools_tests "/home/pf/rosWS/src/frontier_exploration-build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/pf/rosWS/src/frontier_exploration-build/test_results/frontier_exploration/gtest-costmap_tools_tests.xml" "--return-code" "/home/pf/rosWS/src/frontier_exploration-build/devel/lib/frontier_exploration/costmap_tools_tests --gtest_output=xml:/home/pf/rosWS/src/frontier_exploration-build/test_results/frontier_exploration/gtest-costmap_tools_tests.xml")
SUBDIRS(gtest)
