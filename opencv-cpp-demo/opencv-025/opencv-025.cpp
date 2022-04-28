#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
RNG rng(12345);

int main(int argc, char** argv)
{
     Mat src = imread("f:/images/qq/20200215213837.png");
    //Mat src = imread("f:/images/qq/yezi.png");
    if (src.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }

    namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input", src);

    // ��һ����˹ģ��������һЩϸ΢�Ķ���
    GaussianBlur(src, src, Size(3, 3), 0);
    GaussianBlur(src, src, Size(3, 3), 0);

    Mat gray, binary;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    imshow("gray", gray);

    // ��ֵ��
    threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
    imshow("binary", binary);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    //findContours(binary, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
    // ֻ��������������
    findContours(binary, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());

    // һ��һ������
    for (size_t t = 0; t < contours.size(); t++) {
        double area = contourArea(contours[t]);
        double len = arcLength(contours[t], true);
        printf("#%d === area: %.2f, length: %.2f\n", t, area, len);
        // ������������˽�С��������ܳ�������, 2��Ϊ-1����������������
        drawContours(src, contours, t, Scalar(0, 0, 255), 1, 8);
        Rect box = boundingRect(contours[t]);
        //rectangle(src, box, Scalar(255, 0, 0), 1, 8);
        // ��С��Ӿ��ξ���
        Point2f pts[4];
        RotatedRect rrt = minAreaRect(contours[t]);
        rrt.points(pts);
        for (int i = 0; i < 4; i++) {
            line(src, pts[i], pts[(i+1)%4], Scalar(0, 255, 255), 1, 8);
        }
        // ���������Բ
        //ellipse(src, rrt, Scalar(255, 255, 0), 1, 8);
    }

    // -1�����������
    //drawContours(src, contours, -1, Scalar(0, 0, 255), 2, 8);
    imshow("result", src);

    waitKey(0);
    destroyAllWindows();

    return 0;
}

