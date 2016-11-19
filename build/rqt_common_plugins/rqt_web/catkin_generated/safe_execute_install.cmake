execute_process(COMMAND "/home/pf/rosWS/build/rqt_common_plugins/rqt_web/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/pf/rosWS/build/rqt_common_plugins/rqt_web/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
