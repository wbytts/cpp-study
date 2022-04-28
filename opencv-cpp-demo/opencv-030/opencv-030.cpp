#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
    Mat src = imread("f:/images/shuang001.jpg");

    Mat gray, binary;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
    imshow("src", src);
    imshow("binary", binary);
    Mat dst1, dst2;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
    // ��ʴ
    //erode(binary, binary, kernel);
    // ���Դ����ɫͼ��
    erode(src, dst1, kernel);
    // ����
    dilate(src, dst2, kernel);

    imshow("erode", dst1);
    imshow("dilate", dst2);

    waitKey(0);
    destroyAllWindows();

    return 0;
}


