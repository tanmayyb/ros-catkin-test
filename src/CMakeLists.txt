cmake_minimum_required(VERSION 3.0.2)
project(bimanual_planning_ros)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# CUDA stuff
set(CMAKE_C_COMPILER "/usr/lib/nvidia-cuda-toolkit/bin/gcc" CACHE PATH "" FORCE)
set(CMAKE_CXX_COMPILER "/usr/lib/nvidia-cuda-toolkit/bin/g++" CACHE PATH "" FORCE)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# CUDA stuff
set(CUDA_DIR "/usr/lib/nvidia-cuda-toolkit")
find_package(CUDA REQUIRED)
SET(CUDA_NVCC_FLAGS "-arch=sm_75" CACHE STRING "nvcc flags" FORCE)
SET (CUDA_VERBOSE_BUILD ON CACHE BOOL "nvcc verbose" FORCE)
# SET(LIB_TYPE STATIC) 
enable_language(CUDA)
# to supress warnings
add_definitions(-w -DUSE_CUDA)


find_package(catkin REQUIRED COMPONENTS
  actionlib
  controller_interface
  franka_gripper
  franka_hw
  franka_msgs
  geometry_msgs
  hardware_interface
  message_generation
  moveit_core
  moveit_msgs
  moveit_ros_planning
  moveit_ros_planning_interface
  moveit_visual_tools
  pluginlib
  realtime_tools
  roscpp
  rospy
  std_msgs
  tf2_geometry_msgs
  tf2_ros
  visualization_msgs
  eigen_conversions
)


find_package(Eigen3 REQUIRED)
find_package(Franka 0.7.0 REQUIRED)
find_package(Poco REQUIRED COMPONENTS Foundation)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


catkin_package(
  INCLUDE_DIRS include
#   LIBRARIES utilities dual_panda_costp_controller
  CATKIN_DEPENDS
    actionlib
    controller_interface
    franka_gripper
    franka_hw
    franka_msgs
    geometry_msgs
    hardware_interface
    message_runtime
    moveit_core
    moveit_msgs
    moveit_ros_planning
    moveit_ros_planning_interface
    moveit_visual_tools
    pluginlib
    roscpp
    rospy
    std_msgs
    tf2_geometry_msgs
    tf2_ros
    visualization_msgs
  DEPENDS
    Poco
    Franka
)


include_directories(PUBLIC
  include
)



add_executable(panda_bimanual_control_node
  src/main.cpp
  src/helper.cpp
  src/dummy.cpp
)


add_dependencies(panda_bimanual_control_node
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)

target_include_directories(panda_bimanual_control_node SYSTEM PUBLIC
  ${catkin_INCLUDE_DIRS}
)
target_link_libraries(panda_bimanual_control_node
  ${catkin_LIBRARIES}
  ${CUDA_LIBRARIES}
)


# install(TARGETS dual_panda_costp_controller
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )
