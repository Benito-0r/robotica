#include <ros/ros.h>
#include "m20ia_msgs/m20ia_srv.h"

#include <geometry_msgs/Transform.h>
#include <tf_conversions/tf_eigen.h>

#include <moveit/robot_state/conversions.h>
#include <moveit_msgs/RobotState.h>
#include <moveit/robot_state/robot_state.h>
#include <moveit/robot_model_loader/robot_model_loader.h>

bool fk(m20ia_msgs::m20ia_srv::Request &request, m20ia_msgs::m20ia_srv::Response &response)
{

  robot_model_loader::RobotModelLoader robot_model_loader;
  robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
  robot_state::RobotState robot_state(kinematic_model);
  robot_state::robotStateMsgToRobotState(request.robot_state, robot_state);
  robot_state::RobotStatePtr kinematic_state(new robot_state::RobotState(robot_state.getRobotModel()));
  kinematic_state->setToDefaultValues();
  Eigen::Isometry3d joint[7];
  tf::Matrix3x3 tf_matrix[7];
  tf::Vector3 tf_vector[7];
  tf::Quaternion q[7];
  geometry_msgs::Transform joint_trasformed[7];

  for (int i = 0; i < 7; i++)
  {
    joint[i] = kinematic_state->getGlobalLinkTransform(request.frame_id[i]);

    tf::matrixEigenToTF(joint[i].rotation(), tf_matrix[i]);
    tf_matrix[i].getRotation(q[i]);
    tf::vectorEigenToTF(joint[i].translation(), tf_vector[i]);
  }
 
  response.fk_link_name=request.fk_link_name;

  response.frame_id.resize(7);
  response.pose_stamped.resize(7); 
  for (int i = 0; i < 7; i++)
  { 
    response.frame_id[i] = request.frame_id[i];
    
    response.pose_stamped[i].position.x = tf_vector[i].getX();
    response.pose_stamped[i].position.y = tf_vector[i].getY();
    response.pose_stamped[i].position.z = tf_vector[i].getZ();

    response.pose_stamped[i].orientation.x = q[i].getX();
    response.pose_stamped[i].orientation.y = q[i].getY();
    response.pose_stamped[i].orientation.z = q[i].getZ();
    response.pose_stamped[i].orientation.w = q[i].getW();
    
  }
  
  ROS_INFO_STREAM("Riposta inviata:\n" << response);
  return true;
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "m20ia_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("m20ia_fk", fk);
  ROS_INFO("Pronto ad operare.");
  ros::spin();

  return 0;
}