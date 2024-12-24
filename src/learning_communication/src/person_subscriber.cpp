#include <ros/ros.h>
#include "learning_communication/PersonMsg.h"

void personInfoCallback(const learning_communication::PersonMsg::ConstPtr& msg)
{
     ROS_INFO("Subcriber Person Info: name:%s  age:%d  sex:%d",  msg->name.c_str(), msg->age, msg->sex);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "person_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber person_sub = nh.subscribe("person_info", 10, personInfoCallback);
    ros::spin();
    return 0;
}