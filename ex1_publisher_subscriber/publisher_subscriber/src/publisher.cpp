#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <time.h> 
#include <string>
using namespace std;

int main(int argc,char ** argv){
    ros::init(argc,argv,"talker");
    ros::NodeHandle nh;
    ros::Publisher chatterPublisher =
    nh.advertise <trajectory_msgs::JointTrajectory>("motor_chatter",1);
    ros::Rate loopRate(1);

    srand(time(NULL));

    while (ros::ok())
    {
        trajectory_msgs::JointTrajectory  robot;
        trajectory_msgs::JointTrajectoryPoint  msg1,msg2,msg3,msg4,msg5,msg6;
        
        for(int i=1;i<7;i++){        
            robot.joint_names.push_back("joint"+to_string(i));
        }
        
        robot.points.push_back(msg1);
        robot.points.push_back(msg2);
        robot.points.push_back(msg3);
        robot.points.push_back(msg4);
        robot.points.push_back(msg5);
        robot.points.push_back(msg6);
        
        for(int i=0;i<6;i++){
            robot.points[i].positions.resize(5);
            for(int j=0;j<5;j++){
                robot.points[i].positions[j] = rand();
            }
        }
        
        for(int i=0;i<6;i++){
            ROS_INFO_STREAM("Giunto:"<<robot.joint_names[i]);
            ROS_INFO_STREAM(robot.points[i]); 
        }
        
        
        chatterPublisher.publish(robot);
        
        ros::spinOnce();
        loopRate.sleep();
        
    }
    return 0;    
}