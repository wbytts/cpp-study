#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat src = imread("f:/images/lena.jpg");
    if (src.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }

    namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input", src);

    
    Mat grad_x, grad_y;
    Mat result;

    // robot
    Mat robot_x = (Mat_<int>(2, 2) << 1, 0, 0, -1);
    Mat robot_y = (Mat_<int>(2, 2) << 0, 1, -1, 0);
    filter2D(src, grad_x, CV_32F, robot_x, Point(-1, -1), 0, BORDER_DEFAULT);
    filter2D(src, grad_y, CV_32F, robot_y, Point(-1, -1), 0, BORDER_DEFAULT);
    convertScaleAbs(grad_x, grad_x);
    convertScaleAbs(grad_y, grad_y);
    imshow("robot_x", grad_x);
    imshow("robot_y", grad_y);
    add(grad_x, grad_y, result);
    imshow("robot_result", result);

    // sobel
    Sobel(src, grad_x, CV_32F, 1, 0, 3);
    Sobel(src, grad_y, CV_32F, 0, 1, 3);
    convertScaleAbs(grad_x, grad_x);
    convertScaleAbs(grad_y, grad_y);
    imshow("sobel_x", grad_x);
    imshow("sobel_y", grad_y);
    //add(grad_x, grad_y, result);
    addWeighted(grad_x, 0.5, grad_y, 0.5, 0, result);
    imshow("sobel_result", result);

    // scharr
    Scharr(src, grad_x, CV_32F, 1, 0, 3);
    Scharr(src, grad_y, CV_32F, 0, 1, 3);
    convertScaleAbs(grad_x, grad_x);
    convertScaleAbs(grad_y, grad_y);
    imshow("scharr_x", grad_x);
    imshow("scharr_y", grad_y);
    //add(grad_x, grad_y, result);
    addWeighted(grad_x, 0.5, grad_y, 0.5, 0, result);
    imshow("scharr_result", result);

    waitKey(0);
    destroyAllWindows();

    return 0;
}