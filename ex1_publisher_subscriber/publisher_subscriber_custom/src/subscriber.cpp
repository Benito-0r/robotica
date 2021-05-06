#include <ros/ros.h>
#include <std_msgs/String.h>
#include "publisher_subscriber_msgs/InfoJoint.h"
#include "publisher_subscriber_msgs/JointCustomMsg.h"
using namespace std;
#include <iostream>

void chatterCallback(const publisher_subscriber_msgs::JointCustomMsg& msg)
{
    for (int i=0;i<6;i++){
        ROS_INFO_STREAM("Giunto:"<<msg.joint_names[i]);
        ROS_INFO_STREAM("Posizioni: "<<msg.info[i]);
    }
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber =
    nodeHandle.subscribe("motor_chatter",10,chatterCallback);
    ros::spin();
    return 0;
}