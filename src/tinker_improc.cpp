// http://wiki.ros.org/vision_opencv

#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main() {

    // w.r.t. catkin_ws
    const auto IM_PATH = "src/alexsm_ball_chaser/data/images/wb_3.png";
    
    cv::Mat im;
    im = cv::imread(IM_PATH, cv::IMREAD_GRAYSCALE);
    std::cout << "Image shape: " << im.size() << std::endl;

    cv::Mat im_t;
    cv::threshold(im, im_t, 250, 255, cv::THRESH_BINARY);

    cv::Mat labels;
    cv::Mat stats;
    cv::Mat centroids;

    cv::connectedComponentsWithStats(im_t, labels, stats, centroids);

    std::cout << centroids.size() << std::endl;
    std::cout << centroids.row(1) << std::endl;

    cv::namedWindow("image_show", cv::WINDOW_AUTOSIZE);
    cv::imshow("image_show", im_t);
    cv::waitKey();

    return 0;
}