#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "alexsm_ball_chaser/DriveToTarget.h"

using geometry_msgs::Twist;

ros::Publisher pub;

int main(int argc, char* argv[]) {

    ros::init(argc, argv, "drive_bot");
    ros::NodeHandle this_node;

    pub = this_node.advertise<Twist>(
        "/cmd_vel", 
        10
    );

    while (ros::ok()) {

        Twist twist_cmd;
        twist_cmd.linear.x = 0.1;
        twist_cmd.angular.z = 0.1;

        pub.publish(twist_cmd);
    }


    return 0;

}