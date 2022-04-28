#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
    Mat src = imread("f:/images/qq/kaibi.png");

    Mat gray, binary;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
    imshow("src", src);
    imshow("binary", binary);
    Mat dst;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(4, 4), Point(-1, -1));

    // ����������ȡˮƽ����
    //Mat kernel = getStructuringElement(MORPH_RECT, Size(15, 1), Point(-1, -1));
    
    morphologyEx(src, dst, MORPH_OPEN, kernel, Point(-1, -1), 1);
    //morphologyEx(src, dst, MORPH_CLOSE, kernel, Point(-1, -1), 1);
    imshow("morphologyEx", dst);

    waitKey(0);
    destroyAllWindows();

    return 0;
}


