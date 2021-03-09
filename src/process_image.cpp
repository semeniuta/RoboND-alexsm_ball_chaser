#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "cv_bridge/cv_bridge.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "alexsm_ball_chaser/DriveToTarget.h"

const int N_PIXELS = 640000; // 800 x 800
const char* OPENCV_WINDOW = "stream";

ros::ServiceClient client;

void improc_callback(const sensor_msgs::Image ros_im) {

    cv_bridge::CvImagePtr im;
    im = cv_bridge::toCvCopy(ros_im, sensor_msgs::image_encodings::BGR8);

    cv::imshow(OPENCV_WINDOW, im->image);
    cv::waitKey(3);
}

int main(int argc, char* argv[]) {

    ros::init(argc, argv, "process_image");
    ros::NodeHandle this_node;

    cv::namedWindow(OPENCV_WINDOW, cv::WINDOW_AUTOSIZE);

    client = this_node.serviceClient<alexsm_ball_chaser::DriveToTarget>(
        "ball_chaser/command_robot"
    );

    ros::Subscriber sub = this_node.subscribe(
        "/camera/rgb/image_raw",
        10,
        improc_callback
    );

    ros::spin();

    return 0;
}