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

    int h = src.rows;
    int w = src.cols;
    Mat result = src.clone();
    for (int row = 1; row < h - 1; row++) {
        for (int col = 1; col < w - 1; col++) {
            // 3x3卷积核
            int sb =
                src.at<Vec3b>(row, col)[0] +
                src.at<Vec3b>(row - 1, col - 1)[0] +
                src.at<Vec3b>(row - 1, col)[0] +
                src.at<Vec3b>(row - 1, col + 1)[0] +
                src.at<Vec3b>(row, col - 1)[0] +
                src.at<Vec3b>(row, col + 1)[0] +
                src.at<Vec3b>(row + 1, col - 1)[0] +
                src.at<Vec3b>(row + 1, col)[0] +
                src.at<Vec3b>(row + 1, col + 1)[0];
            int sg =
                src.at<Vec3b>(row, col)[1] +
                src.at<Vec3b>(row - 1, col - 1)[1] +
                src.at<Vec3b>(row - 1, col)[1] +
                src.at<Vec3b>(row - 1, col + 1)[1] +
                src.at<Vec3b>(row, col - 1)[1] +
                src.at<Vec3b>(row, col + 1)[1] +
                src.at<Vec3b>(row + 1, col - 1)[1] +
                src.at<Vec3b>(row + 1, col)[1] +
                src.at<Vec3b>(row + 1, col + 1)[1];
            int sr =
                src.at<Vec3b>(row, col)[2] +
                src.at<Vec3b>(row - 1, col - 1)[2] +
                src.at<Vec3b>(row - 1, col)[2] +
                src.at<Vec3b>(row - 1, col + 1)[2] +
                src.at<Vec3b>(row, col - 1)[2] +
                src.at<Vec3b>(row, col + 1)[2] +
                src.at<Vec3b>(row + 1, col - 1)[2] +
                src.at<Vec3b>(row + 1, col)[2] +
                src.at<Vec3b>(row + 1, col + 1)[2];
            result.at<Vec3b>(row, col)[0] = sb / 9;
            result.at<Vec3b>(row, col)[1] = sg / 9;
            result.at<Vec3b>(row, col)[2] = sr / 9;
        }
    }

    imshow("result", result);

    Mat dst;
    /*
       blur参数：
            src：输入
            dst：输出
            ksize：卷积核大小
            anchor：锚定点，默认(-1,-1)，中心位置（默认是卷积核大小除以2的位置）
            borderType：边缘处理方式，默认为BORDER_DEFAULT=4
    */
    blur(src, dst, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
    imshow("dst", dst);

    // 边缘填充 copyMakeBorder
    int border = 8;
    Mat border_m;
    copyMakeBorder(src, border_m, border, border, border, border, BORDER_WRAP, Scalar(0, 0, 255));
    imshow("border fill demo", border_m);

    waitKey(0);
    destroyAllWindows();

    return 0;
}