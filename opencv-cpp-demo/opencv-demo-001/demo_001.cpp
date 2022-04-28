#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int demo001()
{
    // ͼ���ڴ������C++������Mat������ʽ�����
    Mat img = imread("C:\\Users\\hp\\Desktop\\Emoticon\\q.jpg");

    // ��ȡ�Ҷ�ͼ��
    //Mat img = imread("C:\\Users\\hp\\Desktop\\Emoticon\\q.jpg", IMREAD_GRAYSCALE);

    if (img.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }

    // �������ڣ�WINDOW_AUTOSIZE����ʾ��С��ͼ�����
    namedWindow("input", WINDOW_AUTOSIZE);

    // ��ָ����������ʾһ��ͼ��
    imshow("input", img);

    // ɫ�ʿռ�ת��
    Mat gray;
    // ת��Ϊ�Ҷ�ͼ��
    // ����1��Ҫת����ͼ�񣬲���2���洢ת������ģ�����3��ת����ѡ��
    cvtColor(img, gray, COLOR_BGR2GRAY);

    // ��ͼ��д���ļ�
    // ���ͼ�������������ˣ��ǲ�������ʾ��
    imwrite("f:\\temp\\test\\gray.png", gray);

    waitKey(0);

    // �������д���
    destroyAllWindows();
}

int demo002()
{
    /*
        imread���������ڶ�ȡͼ��

    */
    Mat img = imread("f:/temp/images/lena.jpg");
    /*
        imshow����������ͼ�����ʾ
    */

    /*
        imwrite����������д��ͼ���ļ�
    */
}

int main(int argc, char** argv)
{

    int ret = demo001();

    return ret;
}