#include <ros/ros.h>
#include "learning_communication/PersonMsg.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "person_publisher");
    ros::NodeHandle nh;
    ros::Publisher person_info_pub = nh.advertise<learning_communication::PersonMsg>("person_info", 100);
    ros::Rate loop_rate(1);

    int count = 0;
    while (ros::ok())
    {
        learning_communication::PersonMsg person_msg;
        person_msg.name = "Tom";
        person_msg.age = 18;
        person_msg.sex = learning_communication::PersonMsg::male;

        person_info_pub.publish(person_msg);
        ROS_INFO("Publish Person Info: name:%s  age:%d  sex:%d", person_msg.name.c_str(), person_msg.age, person_msg.sex);
        loop_rate.sleep();
    }

    return 0;
}