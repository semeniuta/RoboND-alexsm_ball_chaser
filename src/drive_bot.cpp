#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "alexsm_ball_chaser/DriveToTarget.h"

using geometry_msgs::Twist;
using alexsm_ball_chaser::DriveToTarget;

ros::Publisher pub;


bool service_callback(DriveToTarget::Request& req, DriveToTarget::Response& res) {

    Twist twist_cmd;
    twist_cmd.linear.x = req.linear_x;
    twist_cmd.angular.z = req.angular_z;

    pub.publish(twist_cmd);

    ros::Duration(0.25).sleep();

    res.msg_feedback = "Published twist(linear_x, angular_z): " 
                       + std::to_string(req.linear_x) + ", "
                       + std::to_string(req.angular_z);

    return true;

}


int main(int argc, char* argv[]) {

    ros::init(argc, argv, "drive_bot");
    ros::NodeHandle this_node;

    pub = this_node.advertise<Twist>(
        "/cmd_vel", 
        10
    );

    ros::ServiceServer service = this_node.advertiseService(
        "/ball_chaser/command_robot",
        service_callback
    );

    // while (ros::ok()) {

    //     Twist twist_cmd;
    //     twist_cmd.linear.x = 0.1;
    //     twist_cmd.angular.z = 0.1;

    //     pub.publish(twist_cmd);
    // }

    ros::spin();

    return 0;

}