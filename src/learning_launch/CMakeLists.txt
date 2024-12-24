cmake_minimum_required(VERSION 3.0.2)
project(learning_launch)


find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
  std_srvs
)


catkin_package()


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(publisher src/publisher.cpp)
target_link_libraries(publisher ${catkin_LIBRARIES})

add_executable(subscriber src/subscriber.cpp)
target_link_libraries(subscriber ${catkin_LIBRARIES})