#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
    Mat src = imread("f:/images/qq/circle.png");
    //Mat src = imread("f:/images/qq/yezi.png");
    if (src.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }

    namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input", src);

    Mat gray;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray, Size(9,3), 2, 2);
    imshow("gray", gray);

    vector<Vec3f> circles;
    int minDist = 20;
    double min_radius = 5;
    double max_radius = 100;
    // ���ջҶ�ͼ��Ҫ���룬������������
    HoughCircles(gray, circles, HOUGH_GRADIENT, 1, minDist, 100, 100, max_radius, min_radius);
    for (size_t t = 0; t < circles.size(); t++) {
        Point center(circles[t][0], circles[t][1]);
        int radius = round(circles[t][2]);
        // ����Բ
        circle(src, center, radius, Scalar(0, 0, 255), 2, 8, 0);
        circle(src, center, 3, Scalar(255, 0, 0), 2, 8, 0);
    }

    imshow("hough circle demo", src);
    
    waitKey(0);
    destroyAllWindows();

    return 0;
}


