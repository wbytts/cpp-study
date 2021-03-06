#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void hough_linesp_demo();

int main(int argc, char** argv)
{
    Mat src = imread("f:/images/qq/tline.png");
    //Mat src = imread("f:/images/qq/yezi.png");
    if (src.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }

    namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input", src);

    // 做一个高斯模糊，消除一些细微的东西
    //GaussianBlur(src, src, Size(3, 3), 0);

    Mat gray, binary;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    imshow("gray", gray);

    // 二值化
    threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
    imshow("binary", binary);

    // 霍夫直线检测
    vector<Vec3f> lines;
    HoughLines(binary, lines, 1, CV_PI / 180.0, 100, 0, 0);
    // 绘制直线
    Point pt1, pt2;
    for (size_t i = 0; i < lines.size(); i++) {
        float rho = lines[i][0]; // 距离
        float theta = lines[i][1]; // 角度
        float acc = lines[i][2]; // 累加值
        printf("rho: %.2f, thrta: %.2f, acc: %.2f\n", rho, theta, acc);
        double a = cos(theta);
        double b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        pt1.x = cvRound(x0 + 1000 * (-b));
        pt1.y = cvRound(y0 + 1000 * (a));
        pt2.x = cvRound(x0 - 1000 * (-b));
        pt2.y = cvRound(y0 - 1000 * (a));
        int angle = round((theta / CV_PI) * 180);
        if (rho > 0) { //右倾
            line(src, pt1, pt2, Scalar(0, 0, 255), 2, 8, 0);
            if (angle == 90) { // 水平线
                line(src, pt1, pt2, Scalar(0, 255, 255), 2, 8, 0);
            }
            if (angle < 1) { // 近似垂直线
                line(src, pt1, pt2, Scalar(255, 255, 0), 2, 8, 0);
            }
        }
        else { // 左倾
            line(src, pt1, pt2, Scalar(255, 0, 0), 2, 8, 0);
        }
        
    }
    imshow("hough line detection", src);
    hough_linesp_demo();
    waitKey(0);
    destroyAllWindows();

    return 0;
}

void hough_linesp_demo() {
    Mat src = imread("f:/images/qq/tline.png");
    Mat gray, binary;
    Canny(src, binary, 80, 160, 3, false);
    imshow("canny binary", binary);

    vector<Vec4i> lines;
    HoughLinesP(binary, lines, 1, CV_PI / 180, 80, 30, 10);
    Mat result = Mat::zeros(src.size(), src.type());
    for (int i = 0; i < lines.size(); i++) {
        line(result, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 2, 8, 0);
    }
    imshow("hough linesp demo", result);
}
