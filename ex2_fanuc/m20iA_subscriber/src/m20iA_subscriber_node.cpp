#include<ros/ros.h>
#include<tf2_ros/transform_listener.h>
#include<geometry_msgs/TransformStamped.h>
#include<tf/tf.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "tf2_listener");

    tf2_ros::Buffer tfBuffer[6];
    tf2_ros::TransformListener tfListener(tfBuffer[0]),tfListener1(tfBuffer[1]),tfListener2(tfBuffer[2]),
    tfListener3(tfBuffer[3]), tfListener4(tfBuffer[4]),tfListener5(tfBuffer[5]),tfListener6(tfBuffer[6]);
    double roll,pitch,yaw;
    
    ros::Rate rate(10.0);
    while(ros::ok()) {
        geometry_msgs::TransformStamped transformStamped;
        
        try{
            for(int i=1;i<7;i++){
            transformStamped = tfBuffer[i-1].lookupTransform("base_link","link_"+std::to_string(i), ros::Time(0));
            
            tf::Quaternion quaternion(transformStamped.transform.rotation.x,transformStamped.transform.rotation.y,
                            transformStamped.transform.rotation.z,transformStamped.transform.rotation.w);

            tf::Matrix3x3   matrix_rotation(quaternion);

            matrix_rotation.getRPY(roll,pitch,yaw);
            geometry_msgs::Quaternion  quat_msg;
            geometry_msgs::Vector3 v0,v1,v2,axis;
            tf::vector3TFToMsg(matrix_rotation.getColumn(0),v0);
            tf::vector3TFToMsg(matrix_rotation.getColumn(1),v1);
            tf::vector3TFToMsg(matrix_rotation.getColumn(2),v2);
            tf::vector3TFToMsg(quaternion.getAxis(),axis);
            tf::quaternionTFToMsg(quaternion,quat_msg);
            
                        ROS_INFO_STREAM(transformStamped.header<<"child_id: "<<transformStamped.child_frame_id<<
                                        "\n\nTranslation:["<<transformStamped.transform.translation.x<<" , "<<
                                                            transformStamped.transform.translation.y<<" , "<<
                                                            transformStamped.transform.translation.z<<            
                                                            "]\n\nQuaternion:["  << quat_msg.x<<" , "<<quat_msg.y<<" , "<<quat_msg.z<<" , "<<quat_msg.w<<
                                                            "]\n\nMatrice di rotazione: \n[" << v0.x <<", "<<v0.y<<" , "<<v0.z <<
                                                            "]\n["<<v1.x <<" , "<<v1.y<<" , "<<v1.z << 
                                                            "]\n["<<v2.x <<" , "<<v2.y<<" , "<<v2.z << 
                                                            "]\n\nRPY:["<<roll<<" , "<<pitch<<" , "<<yaw<<"]"<<
                                                            "\n\nAsse:["<<axis.x<<","<<axis.y<<", "<<axis.z <<"]  Angolo: " <<quaternion.getAngle()<<"\n"
                                                            );

            }
        } catch (tf2::TransformException &exception) {
            ROS_WARN("%s", exception.what());
            ros::Duration(1.0).sleep();
            continue;
        }
        rate.sleep();
    }
    return 0;
};