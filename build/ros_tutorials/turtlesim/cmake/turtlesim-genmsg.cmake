# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "turtlesim: 2 messages, 5 services")

set(MSG_I_FLAGS "-Iturtlesim:/home/pf/rosWS/src/ros_tutorials/turtlesim/msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(turtlesim_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportAbsolute.srv" NAME_WE)
add_custom_target(_turtlesim_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlesim" "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportAbsolute.srv" ""
)

get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Color.msg" NAME_WE)
add_custom_target(_turtlesim_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlesim" "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Color.msg" ""
)

get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/SetPen.srv" NAME_WE)
add_custom_target(_turtlesim_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlesim" "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/SetPen.srv" ""
)

get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Pose.msg" NAME_WE)
add_custom_target(_turtlesim_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlesim" "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Pose.msg" ""
)

get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportRelative.srv" NAME_WE)
add_custom_target(_turtlesim_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlesim" "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportRelative.srv" ""
)

get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Spawn.srv" NAME_WE)
add_custom_target(_turtlesim_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlesim" "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Spawn.srv" ""
)

get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Kill.srv" NAME_WE)
add_custom_target(_turtlesim_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlesim" "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Kill.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Color.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim
)
_generate_msg_cpp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim
)

### Generating Services
_generate_srv_cpp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportAbsolute.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim
)
_generate_srv_cpp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Spawn.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim
)
_generate_srv_cpp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/SetPen.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim
)
_generate_srv_cpp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportRelative.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim
)
_generate_srv_cpp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Kill.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim
)

### Generating Module File
_generate_module_cpp(turtlesim
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(turtlesim_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(turtlesim_generate_messages turtlesim_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportAbsolute.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_cpp _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Color.msg" NAME_WE)
add_dependencies(turtlesim_generate_messages_cpp _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/SetPen.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_cpp _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Pose.msg" NAME_WE)
add_dependencies(turtlesim_generate_messages_cpp _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportRelative.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_cpp _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Spawn.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_cpp _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Kill.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_cpp _turtlesim_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlesim_gencpp)
add_dependencies(turtlesim_gencpp turtlesim_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlesim_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Color.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim
)
_generate_msg_lisp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim
)

### Generating Services
_generate_srv_lisp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportAbsolute.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim
)
_generate_srv_lisp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Spawn.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim
)
_generate_srv_lisp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/SetPen.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim
)
_generate_srv_lisp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportRelative.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim
)
_generate_srv_lisp(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Kill.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim
)

### Generating Module File
_generate_module_lisp(turtlesim
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(turtlesim_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(turtlesim_generate_messages turtlesim_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportAbsolute.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_lisp _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Color.msg" NAME_WE)
add_dependencies(turtlesim_generate_messages_lisp _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/SetPen.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_lisp _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Pose.msg" NAME_WE)
add_dependencies(turtlesim_generate_messages_lisp _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportRelative.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_lisp _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Spawn.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_lisp _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Kill.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_lisp _turtlesim_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlesim_genlisp)
add_dependencies(turtlesim_genlisp turtlesim_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlesim_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Color.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim
)
_generate_msg_py(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim
)

### Generating Services
_generate_srv_py(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportAbsolute.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim
)
_generate_srv_py(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Spawn.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim
)
_generate_srv_py(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/SetPen.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim
)
_generate_srv_py(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportRelative.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim
)
_generate_srv_py(turtlesim
  "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Kill.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim
)

### Generating Module File
_generate_module_py(turtlesim
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(turtlesim_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(turtlesim_generate_messages turtlesim_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportAbsolute.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_py _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Color.msg" NAME_WE)
add_dependencies(turtlesim_generate_messages_py _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/SetPen.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_py _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/msg/Pose.msg" NAME_WE)
add_dependencies(turtlesim_generate_messages_py _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/TeleportRelative.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_py _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Spawn.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_py _turtlesim_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pf/rosWS/src/ros_tutorials/turtlesim/srv/Kill.srv" NAME_WE)
add_dependencies(turtlesim_generate_messages_py _turtlesim_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlesim_genpy)
add_dependencies(turtlesim_genpy turtlesim_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlesim_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(turtlesim_generate_messages_cpp geometry_msgs_generate_messages_cpp)
add_dependencies(turtlesim_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(turtlesim_generate_messages_cpp std_srvs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(turtlesim_generate_messages_lisp geometry_msgs_generate_messages_lisp)
add_dependencies(turtlesim_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(turtlesim_generate_messages_lisp std_srvs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(turtlesim_generate_messages_py geometry_msgs_generate_messages_py)
add_dependencies(turtlesim_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(turtlesim_generate_messages_py std_srvs_generate_messages_py)
