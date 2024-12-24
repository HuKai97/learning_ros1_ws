#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("subscriber : [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    // 初始化Ros节点 节点名为string_subscriber  不可重复
    ros::init(argc, argv, "string_subscriber");
    // 创建ros句柄 负责创建、管理通信的资源（如话题、服务等）
    ros::NodeHandle nh;
    // 创建一个订阅者sub，订阅topic名为chatter的话题，发现有数据进来后，调用回调函数chatterCallback   缓冲区大小1000
    ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);
    // 循环等待回调函数; 这个是死循环
    ros::spin();
    return 0;
}