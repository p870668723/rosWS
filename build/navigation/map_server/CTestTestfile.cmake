# CMake generated Testfile for 
# Source directory: /home/pf/rosWS/src/navigation/map_server
# Build directory: /home/pf/rosWS/build/navigation/map_server
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(_ctest_map_server_gtest_map_server_utest "/home/pf/rosWS/build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/pf/rosWS/build/test_results/map_server/gtest-map_server_utest.xml" "--return-code" "/home/pf/rosWS/devel/lib/map_server/map_server_utest --gtest_output=xml:/home/pf/rosWS/build/test_results/map_server/gtest-map_server_utest.xml")
ADD_TEST(_ctest_map_server_rostest_test_rtest.xml "/home/pf/rosWS/build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/pf/rosWS/build/test_results/map_server/rostest-test_rtest.xml" "--return-code" "/opt/ros/indigo/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/pf/rosWS/src/navigation/map_server --package=map_server --results-filename test_rtest.xml --results-base-dir \"/home/pf/rosWS/build/test_results\" /home/pf/rosWS/src/navigation/map_server/test/rtest.xml ")
