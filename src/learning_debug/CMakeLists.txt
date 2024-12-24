cmake_minimum_required(VERSION 3.0.2)
project(learning_debug)

# set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)


find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  roslaunch
  rospy
  std_msgs
  std_srvs
)


catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(learning_debug src/publisher.cpp)
target_link_libraries(learning_debug ${catkin_LIBRARIES})