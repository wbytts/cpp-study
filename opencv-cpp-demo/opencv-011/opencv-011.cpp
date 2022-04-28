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

    /*
    ������
        src,dst
        ksize������˴�С
        sigmaX��
        sigmaY��Ĭ��(0,0)
        borderType��Ĭ�� 4
    ��SizeΪ0��0��ʱ��sigma�����Ż������ã�
    sigmaX��sigmaYһ����һ����
    */
    Mat dst;
    GaussianBlur(src, dst, Size(5,5), 0);
    imshow("dst", dst);

    // ����ģ��
    Mat box_dst;
    boxFilter(src, box_dst, -1, Size(5,5), Point(-1, -1), true, BORDER_DEFAULT);
    imshow("boxFilter demo", box_dst);

    waitKey(0);
    destroyAllWindows();

    return 0;
}