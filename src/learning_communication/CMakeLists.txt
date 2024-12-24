cmake_minimum_required(VERSION 3.0.2)
project(learning_communication)

set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_BUILD_TYPE Debug)

# 查找指定项目依赖的catkin包组件
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  std_srvs
  message_generation   # 允许 CMake 根据 .msg 文件生成代码
)

# 添加消息文件 告诉 CMake 生成哪些消息文件
add_message_files(FILES 
    PersonMsg.msg
)

#  使用 generate_messages 指令生成 C++ 和 Python 的消息类  DEPENDENCIES 用于指定依赖的标准消息类型
generate_messages(DEPENDENCIES 
    std_msgs
)

# 声明当前 ROS 包的元信息和依赖关系 告诉 CMake 当前包依赖哪些其他 ROS 包，并且需要哪些构建和运行时支持
# CATKIN_DEPENDS表明当前包在编译是依赖哪些包
catkin_package(CATKIN_DEPENDS 
    roscpp rospy std_msgs std_srvs message_runtime
)

# 自动导入catkin相关依赖的头文件目录
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(string_publisher src/string_publisher.cpp)
# catkin_LIBRARIES是由 find_package catkin生成的变量
target_link_libraries(string_publisher ${catkin_LIBRARIES})

add_executable(string_subscriber src/string_subscriber.cpp)
target_link_libraries(string_subscriber ${catkin_LIBRARIES})

add_executable(person_publisher src/person_publisher.cpp)
target_link_libraries(person_publisher ${catkin_LIBRARIES})

add_executable(person_subscriber src/person_subscriber.cpp)
target_link_libraries(person_subscriber ${catkin_LIBRARIES})