#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

    //Mat src = imread("f:/images/starry_night.jpg", IMREAD_GRAYSCALE);
    Mat src = imread("f:/images/starry_night.jpg");

    if (src.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }

    namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input", src);

    int w = src.cols;
    int h = src.rows;
    int ch = src.channels();

    printf("w: %d, h: %d, ch: %d\n", w, h, ch);

    double min_val;
    double max_val;
    // ���ֵ����Сֵ�����ڵ����ص��λ��
    Point minloc;
    Point maxloc;
    // �ҵ�ͼƬ�������Сֵ
    /* ֻ֧��һ��ͨ�� */
    //minMaxLoc(src, &min_val, &max_val, &minloc, &maxloc, Mat());
    //printf("min: %.2f, max: %.2f\n", min_val, max_val);

    // ����ֵͳ����Ϣ
    vector<int> hist(256);
    for (int i = 0; i < 256; i++) {
        hist.push_back(0);
    }
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            int pv = src.at<uchar>(row, col);
            hist[pv]++; // ͳ��ÿһ������ֵ�ĳ��ִ���
        }
    }

    // ��ֵ������
    Scalar s = mean(src);
    printf("mean: (%.2f, %.2f, %.2f)\n", s[0], s[1], s[2]);
    Mat mm, mstd;
    meanStdDev(src, mm, mstd);
    printf("mstd rows: %d, cols: %d\n", mstd.rows, mstd.cols);
    printf("mm: rows: %d, cols: %d\n", mm.rows, mm.cols);
    printf("mstd: %.2f, %.2f, %.2f\n", mstd.at<double>(0,0), mstd.at<double>(1, 0), mstd.at<double>(2, 0));
    printf("mm: %.2f, %.2f, %.2f\n", mm.at<double>(0, 0), mm.at<double>(1, 0), mm.at<double>(2, 0));
    
    src = Mat::zeros(Size(512, 512), CV_8UC3);
    src = Scalar(0, 0, 255); // ����һ������ɫ��ͼ��
    imshow("red src", src);
    printf("\n\nһ������ɫ��ͼ��\n");

    meanStdDev(src, mm, mstd);
    printf("mstd rows: %d, cols: %d\n", mstd.rows, mstd.cols);
    printf("mm: rows: %d, cols: %d\n", mm.rows, mm.cols);
    printf("mstd: %.2f, %.2f, %.2f\n", mstd.at<double>(0, 0), mstd.at<double>(1, 0), mstd.at<double>(2, 0));
    printf("mm: %.2f, %.2f, %.2f\n", mm.at<double>(0, 0), mm.at<double>(1, 0), mm.at<double>(2, 0));


    waitKey(0);
    destroyAllWindows();

    return 0;
}