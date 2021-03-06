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
    Mat dst;
    Mat basic_grad, inter_grad, exter_grad;

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
    morphologyEx(gray, basic_grad, MORPH_GRADIENT, kernel, Point(-1, -1), 1);

    Mat dst1, dst2;
    erode(gray, dst1, kernel);
    dilate(gray, dst2, kernel);

    subtract(gray, dst1, inter_grad);
    subtract(dst2, gray, exter_grad);

    imshow("basic_grad", basic_grad);
    imshow("inter_grad", inter_grad);
    imshow("exter_grad", exter_grad);

    // 使用基本梯度进行二值化
    threshold(basic_grad, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
    imshow("basic_grad binary", binary);

    waitKey(0);
    destroyAllWindows();

    return 0;
}


