#include <ros/ros.h>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "time_lapse_photography_node");
  ros::NodeHandle nh;

  int video_source = 0;
  cv::VideoCapture cap(video_source);

  if(!cap.isOpened()) return 1;

  cv::namedWindow( "Image", CV_WINDOW_AUTOSIZE );
  cv::Mat frame;
  ros::Rate loop_rate(5);

  while (nh.ok()) {
    cap >> frame;
   // Check if grabbed frame is actually full with some content
    if(!frame.empty()) {
      cv::imshow("Image", frame);
      cv::waitKey(0);
    }
    ros::spinOnce();
    loop_rate.sleep();
  }
  cv::destroyAllWindows();
}
