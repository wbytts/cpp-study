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

    // salt and peper ��������
    RNG rng(12345);
    int h = src.rows;
    int w = src.cols;
    int nums = 10000;
    for (int i = 0; i < nums; i++) {
        int x = rng.uniform(0, w);
        int y = rng.uniform(0, h);
        if (i % 2 == 1) {
            src.at<Vec3b>(y, x) = Vec3b(255, 255, 255);
        }
        else {
            src.at<Vec3b>(y, x) = Vec3b(0, 0, 0);
        }
    }
    imshow("salt and pepper noise", src);
    
    // ��˹����
    Mat image = src.clone();
    Mat noise = Mat::zeros(image.size(), image.type());
    // ͼ�񣬾�ֵ�������ʾһ�����ͼ��
    randn(noise, Scalar(25, 15, 45), Scalar(60, 40, 30));
    Mat dst;
    add(image, noise, dst);
    imshow("gaussian noise", dst);

    waitKey(0);
    destroyAllWindows();

    return 0;
}