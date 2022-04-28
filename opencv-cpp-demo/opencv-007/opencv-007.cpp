#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat src = imread("f:/temp/images/lena.jpg");
    if (src.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }

    namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input", src);

    vector<Mat> mv;
    // ͨ������
    split(src, mv);
    int size = mv.size();
    printf("number of channels: %d\n", size);
    imshow("blue channel", mv[0]);
    imshow("green channel", mv[1]);
    imshow("red channel", mv[2]);

    // �޸�ͨ������Ȼ��ϲ�ͨ��
    mv[2] = Scalar(0);
    // bitwise_not(mv[0], mv[0]);
    Mat dst;
    // ͨ���ϲ�
    merge(mv, dst);
    imshow("merge dst", dst);

    Rect roi;
    roi.x = 100;
    roi.y = 100;
    roi.width = 250;
    roi.height = 200;
    // ��ȡ ROI ����
    // ���ַ�ʽ�ı� sub��ԭͼҲ��ı�
    Mat sub = src(roi);
    // �����Ҫ��Ӱ��ԭͼ������ʹ�� clone������copyTo
    Mat sub2 = src(roi).clone();
    rectangle(src, roi, Scalar(0, 255, 255), 1, 8);
    imshow("roi", sub);
    imshow("src roi", src);

    waitKey(0);
    destroyAllWindows();
}