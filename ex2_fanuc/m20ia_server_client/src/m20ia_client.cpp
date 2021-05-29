#include <ros/ros.h>
#include "m20ia_msgs/m20ia_srv.h"
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_state/robot_state.h>
#include <moveit/robot_state/conversions.h>
#include <moveit_msgs/RobotState.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "m20ia_client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<m20ia_msgs::m20ia_srv>("m20ia_fk");
    m20ia_msgs::m20ia_srv service;

    robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
    robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
    robot_state::RobotState robot_state(kinematic_model);

    moveit_msgs::RobotState robot_msgs_state;

    robot_state::robotStateToRobotStateMsg(robot_state, robot_msgs_state);


    service.request.fk_link_name = "flange";

    service.request.frame_id.resize(7);
    service.request.frame_id[0] = "base_link";
    for (int i = 1; i < 7; i++)
    {
        service.request.frame_id[i] = "link_" + std::to_string(i);
    }

    service.request.robot_state = robot_msgs_state;
 

    if (client.call(service))
    {
        ROS_INFO("Richiesta inviata\n");

        ROS_INFO_STREAM("Risposta dal server:\n"
                        << service.response << "\n");
    }
    else
    {
        ROS_ERROR("Errore nella chiamata!");
        return 1;
    }
    return 0;
}