// http://wiki.ros.org/vision_opencv

#include <iostream>
//#include <filesystem>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main() {

    //std::cout << "Current path: " << std::filesystem::current_path() << std::endl;

    // w.r.t. catkin_ws
    const auto IM_PATH = "src/alexsm_ball_chaser/data/images/wb_2.png";
    
    cv::Mat im;
    im = cv::imread(IM_PATH, cv::IMREAD_GRAYSCALE);

    cv::namedWindow("image_show", cv::WINDOW_AUTOSIZE);
    cv::imshow("image_show", im);
    cv::waitKey();

    return 0;
}