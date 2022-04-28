#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
    Mat src = imread("f:/images/sudoku.png");
    if (src.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }

    namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input", src);

    Mat gray, binary;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    imshow("gray", gray);

    // ��ֵ�ָ�
    Scalar m = mean(gray);
    printf("means: %.2f\n", m[0]);
    threshold(gray, binary, m[0], 255, THRESH_BINARY);
    imshow("binary", binary);

    // ֱ��ͼ
    threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // ����Ӧ��ֵ��ֵ��
    adaptiveThreshold(gray, binary, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 25, 10);
    imshow("ADAPTIVE_THRESH_GAUSSIAN_C ", binary);

    adaptiveThreshold(gray, binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 25, 10);
    imshow("ADAPTIVE_THRESH_MEAN_C ", binary);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
