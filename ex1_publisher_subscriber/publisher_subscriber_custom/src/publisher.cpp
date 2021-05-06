#include <ros/ros.h>
#include "publisher_subscriber_msgs/InfoJoint.h"
#include "publisher_subscriber_msgs/JointCustomMsg.h"
using namespace std;

int main(int argc,char ** argv){
    ros::init(argc,argv,"talker");
    ros::NodeHandle nh;
    ros::Publisher chatterPublisher =
    nh.advertise <publisher_subscriber_msgs::JointCustomMsg>("motor_chatter",1);
    ros::Rate loopRate(1);

    srand(time(NULL));

    while (ros::ok())
    {
        publisher_subscriber_msgs::JointCustomMsg  robot;
        publisher_subscriber_msgs::InfoJoint  pos1,pos2,pos3,pos4,pos5,pos6;
        
        for(int i=1;i<7;i++){        
            robot.joint_names.push_back("joint"+to_string(i));
        }        
        robot.info.push_back(pos1);
        robot.info.push_back(pos2);
        robot.info.push_back(pos3);
        robot.info.push_back(pos4);
        robot.info.push_back(pos5);
        robot.info.push_back(pos6);

        for(int i=0;i<6;i++){
            robot.info[i].positions.resize(5);
            for(int j=0;j<5;j++){
                robot.info[i].positions[j] = rand();
            }
        }                
        
        for(int i=0;i<6;i++){
            ROS_INFO_STREAM("Giunto:"<<robot.joint_names[i]);
            ROS_INFO_STREAM(robot.info[i]); 
        }
  
        chatterPublisher.publish(robot);
        
        ros::spinOnce();
        loopRate.sleep();
        
    }
    return 0;    
}