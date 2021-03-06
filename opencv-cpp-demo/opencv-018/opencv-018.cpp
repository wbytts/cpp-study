#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void add_salt_and_pepper_noise(Mat& image);
void add_gaussian_noise(Mat& image);

int main(int argc, char** argv)
{
    Mat src = imread("f:/images/liu_tou.png");
    if (src.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }

    namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input", src);

    //add_salt_and_pepper_noise(src);
    //add_gaussian_noise(src);
    Mat dst;
    // 中值滤波
    medianBlur(src, dst, 3);
    imshow("median denoise demo", dst);

    // 高斯滤波  高斯滤波对椒盐噪声去噪效果不理想
    GaussianBlur(src, dst, Size(5, 5), 0);
    imshow("guassian denoise demo", dst);

    // 高斯双边
    bilateralFilter(src, dst, 0, 100, 10);
    imshow("bilateralF denoise demo", dst);

    // 如果不加噪声， 直接进行高斯双边，去掉微小细节，保留边缘
    src = imread("f:/images/liu_tou.png");
    bilateralFilter(src, dst, 0, 100, 10);
    imshow("src - bilateralFilter", dst);
    imwrite("f:/liu.png", dst);

    // NLM
    //src = imread("f:/images/liu_tou.png");
    //add_gaussian_noise(src);
    //fastNlMeansDenoisingColored(src, dst, 3., 3., 7, 21);
    //imshow("NLM", dst);

    waitKey(0);
    destroyAllWindows();

    return 0;
}

void add_salt_and_pepper_noise(Mat& image) {
    RNG rng(12345);
    int h = image.rows;
    int w = image.cols;
    int nums = 10000;
    for (int i = 0; i < nums; i++) {
        int x = rng.uniform(0, w);
        int y = rng.uniform(0, h);
        if (i % 2 == 1) {
            image.at<Vec3b>(y, x) = Vec3b(255, 255, 255);
        }
        else {
            image.at<Vec3b>(y, x) = Vec3b(0, 0, 0);
        }
    }
    imshow("salt and pepper noise", image);
}

void add_gaussian_noise(Mat& image) {
    // 高斯噪声
    Mat noise = Mat::zeros(image.size(), image.type());
    // 图像，均值，方差，显示一幅随机图像
    randn(noise, Scalar(15, 25, 45), Scalar(30, 30, 30));
    Mat dst;
    add(image, noise, dst);
    dst.copyTo(image);
    imshow("gaussian noise", image);
}