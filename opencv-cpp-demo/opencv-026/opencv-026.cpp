#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
RNG rng(12345);

void contour_info(Mat &image, vector<vector<Point>> &contours);

int main(int argc, char** argv)
{
    Mat src1 = imread("f:/images/qq/20200215213837.png"); // 查找的图像
    Mat src2 = imread("f:/images/qq/one_mi.png"); //模板
    //Mat src = imread("f:/images/qq/yezi.png");

    if (src1.empty() || src2.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }

    //namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input1", src1);
    imshow("input2", src2);

    vector<vector<Point>> contours1;
    vector<vector<Point>> contours2;
    contour_info(src1, contours1);
    contour_info(src2, contours2);
    
    Moments mm2 = moments(contours2[0]);
    Mat hu2;
    HuMoments(mm2, hu2);

    for (size_t t = 0; t < contours1.size(); t++) {
        Moments mm = moments(contours1[t]);
        // 计算每个轮廓的中心位置
        double cx = mm.m10 / mm.m00;
        double cy = mm.m01 / mm.m00;
        circle(src1, Point(cx, cy), 3, Scalar(0, 255, 0), 2, 8, 0);
        Mat hu;
        HuMoments(mm, hu);
        double dist = matchShapes(hu, hu2, CONTOURS_MATCH_I1, 0);
        if (dist < 1.0) {
            drawContours(src1, contours1, t, Scalar(0, 0, 255), 2, 8);
        }
    }
    imshow("match contours demo", src1);

    waitKey(0);
    destroyAllWindows();

    return 0;
}

void contour_info(Mat& image, vector<vector<Point>>& contours) {
    Mat dst;
    GaussianBlur(image, dst, Size(3, 3), 0);
    Mat gray, binary;
    cvtColor(dst, gray, COLOR_BGR2GRAY);
    threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
    vector<Vec4i> hierarchy;
    findContours(binary, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());
}

