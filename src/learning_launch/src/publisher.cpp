#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    // 初始化 ROS 节点，节点名为string_publisher  不可重复
    ros::init(argc, argv, "publisher");

    // 创建ros句柄 负责创建、管理通信的资源（如话题、服务等）
    ros::NodeHandle nh;

    int max_batch_size;
    max_batch_size = nh.getParam("max_batch_size", max_batch_size);
    std::cout << "max_batch_size: " << max_batch_size << std::endl;

    // 创建发布者 用于向某个话题发布消息  消息类型为std_msgs::String  话题名topic为chatter  队列最长缓存长度为1000
    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);

    //  控制循环频率的工具  10hz
    ros::Rate loop_rate(10);

    int count = 0;

    std::cout << "Start string publisher" << std::endl;

    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();

        ROS_INFO("publish: %s", msg.data.c_str());

        // 将消息发布到话题 chatter 缓冲区中
        chatter_pub.publish(msg);

        // 调整循环频率 10hz
        loop_rate.sleep();
        ++count;
    }

    return 0;
}