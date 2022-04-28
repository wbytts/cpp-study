#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

    Mat src = imread("f:/temp/images/lena.jpg", IMREAD_GRAYSCALE);

    if (src.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }


    namedWindow("002-demo", WINDOW_AUTOSIZE);
    imshow("002-demo", src);

    // ��ȡͼ��Ŀ��
    int width = src.cols;
    // ��ȡͼ��ĸ߶�
    int height = src.rows;
    // ��ȡͼ���ͨ����
    int dim = src.channels();
    int depth = src.depth();
    int type = src.type();

    if (type == CV_8UC1)
    {
        printf("type��CV_8UC1\n");
    }

    /*
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (dim == 3) {
                Vec3b pixel = src.at<Vec3b>(row, col);
                int blue = pixel[0];
                int green = pixel[1];
                int red = pixel[2];
                src.at<Vec3b>(row, col)[0] = 255 - blue;
                src.at<Vec3b>(row, col)[1] = 255 - green;
                src.at<Vec3b>(row, col)[2] = 255 - red;
            }
            if (dim == 1) {
                int pv = src.at<uchar>(row, col);
                src.at<uchar>(row, col) = (255 - pv);
            }
        }
    }
    imshow("fan", src);
    */

    // ָ�뷽ʽ������������ͼ��
    Mat result = Mat::zeros(src.size(), src.type());
    for (int row = 0; row < height; row++) {
        uchar* curr_row = src.ptr<uchar>(row);
        uchar* result_row = result.ptr<uchar>(row);
        for (int col = 0; col < width; col++) {
            if (dim == 3) {
                int blue = *curr_row++;
                int green = *curr_row++;
                int red = *curr_row++;

                *result_row++ = blue;
                *result_row++ = green;
                *result_row++ = red;
            }
            if (dim == 1) {
                int pv = *curr_row++;
                *result_row++ = pv;
            }
        }
    }
    imshow("src", src);


    // �����ӡ����depth��type��ʱ��Ϊ0�������������Ϊ0�����Ǵ���һ��ö�����͵�ֵ
    printf("width: %d, height: %d, dim: %d, depth: %d, type: %d\n", width, height, dim, depth, type);

    // ����mat����
    Mat t1 = Mat(256, 256, CV_8UC3);
    // Scalar(...) ��һ����������ʾһ����ɫֵ
    // �Ҷ�ͼ����һ��ͨ���ģ�һ�������Ϳ���
    t1 = Scalar(0, 0, 255);
    imshow("t1", t1);

    // ����2
    Mat t2 = Mat(Size(512, 512), CV_8UC3);
    t2 = Scalar(255, 0, 255);
    imshow("t2", t2);

    // ����ʱָ����С
    Mat t3 = Mat::zeros(Size(256, 256), CV_8UC3);
    imshow("t3", t3);

    // �����е�ͼ��create
    // ֻ�Ƕ������õĸ�ֵ�������ϻ���һ��ͼ��
    // �����ԭͼ������޸ģ�t4Ҳ�ᱻ�޸�
    Mat t4 = src; 
    // ��¡����һ���µĶ���
    // ��ԭͼ�����޸ģ�t5�����ı�
    Mat t5 = src.clone();
    imshow("t5", t5);

    // ����
    Mat t6;
    src.copyTo(t6);
    imshow("t6", t6);

    // ����һ��������ͼ���С������һ���Ŀհ�ͼ��
    Mat t7 = Mat::zeros(src.size(), src.type());
   
    waitKey(0);
    destroyAllWindows();

    return 0;
}