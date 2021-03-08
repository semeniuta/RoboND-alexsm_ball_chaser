#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "alexsm_ball_chaser/DriveToTarget.h"

ros::ServiceClient client;

void improc_callback(const sensor_msgs::Image ros_im) {

    // TODO

}

int main(int argc, char* argv[]) {

    ros::init(argc, argv, "process_image");
    ros::NodeHandle this_node;

    client = this_node.serviceClient<alexsm_ball_chaser::DriveToTarget>(
        "ball_chaser/command_robot"
    );

    ros::Subscriber sub = this_node.subscribe(
        "/camera/rgb/image_raw",
        10,
        improc_callback
    );

    return 0;
}