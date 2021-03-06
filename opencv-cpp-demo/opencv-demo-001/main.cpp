#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // 图像内存对象，在C++中是以Mat对象形式保存的
    Mat img = imread("f:/images/reba.jpg");
    /*
        imread的默认选项：IMREAD_COLOR，默认会将图像加载为一张 BGR 的彩色图像
            IMREAD_GRAYSCALE：加载一张灰度图像
            IMREAD_ANYCOLOR：
            IMREAD_UNCHANGED：不改变，加载透明通道的图片要使用这个
    */

    // 读取灰度图像
    // Mat img = imread("C:\\Users\\hp\\Desktop\\Emoticon\\q.jpg", IMREAD_GRAYSCALE);

    // 判断图像是否读取成功，如果读取成功，empty返回true
    if (img.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }

    // 创建窗口，默认选项是 WINDOW_AUTOSIZE
    // 选项：
    //      WINDOW_AUTOSIZE：表示自动匹配，不好修改窗口大小
    //      WINDOW_FREEATIO：可以修改窗口的大小
    //      WINDOW_NORMAL：也可以修改窗口
    namedWindow("input", WINDOW_AUTOSIZE);

    // 在指定窗口上显示一张图像
    // imshow 本身不支持透明通道的显示
    imshow("input", img);

    // 色彩空间转换
    Mat gray;
    // 转换为灰度图像
    //       参数1：要转换的图像，
    //       参数2：存储转换结果的，
    //       参数3：转换的选项
    cvtColor(img, gray, COLOR_BGR2GRAY);
    imshow("gray", gray);

    // 将图像写入文件
    // 这个图像如果保存出错了，是不会有提示的！
    imwrite("f:/temp/test/gray.png", gray);

    waitKey(0);

    // 销毁所有窗口
    destroyAllWindows();
}