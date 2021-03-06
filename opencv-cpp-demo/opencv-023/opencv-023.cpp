#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
RNG rng(12345);

void ccl_stats_demo(Mat& image);

int main(int argc, char** argv)
{
    Mat src = imread("f:/images/qq/20200215213837.png");
    if (src.empty())
    {
        printf("Could not find the image!\n");
        return -1;
    }

    namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input", src);
    
    // 做一个高斯模糊，消除一些细微的东西
    GaussianBlur(src, src, Size(3, 3), 0);
    GaussianBlur(src, src, Size(3, 3), 0);

    Mat gray, binary;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    imshow("gray", gray);

    threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
    imshow("binary", binary);

    // 获取联通组件，没有附加信息的
    /*
    Mat labels = Mat::zeros(binary.size(), CV_32S);
    int num_labels = connectedComponents(binary, labels, 8, CV_32S);
    printf("total labels: %d\n", num_labels-1);
    vector<Vec3b> colorTable(num_labels);
    // background color
    colorTable[0] = Vec3b(0, 0, 0);
    for (int i = 1; i < num_labels; i++) {
        colorTable[i] = Vec3b(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
    }

    Mat result = Mat::zeros(src.size(), src.type());
    int w = result.cols;
    int h = result.rows;
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            int label = labels.at<int>(row, col);
            result.at<Vec3b>(row, col) = colorTable[label];
        }
    }
    putText(result, 
        format("number: %d", num_labels - 1), 
        Point(50, 50), FONT_HERSHEY_PLAIN, 1.0, 
        Scalar(0, 255, 0), 1);
    imshow("CCL demo", result);
    */

    // 获取联通组件，有附加信息
    ccl_stats_demo(binary);

    waitKey(0);
    destroyAllWindows();

    return 0;
}

void ccl_stats_demo(Mat& image) {
    Mat labels = Mat::zeros(image.size(), CV_32S);
    Mat stats, centroids;
    int num_labels = connectedComponentsWithStats(image, labels, stats, centroids, 8, CV_32S, CCL_DEFAULT);
    printf("total labels: %d\n", num_labels - 1);
    vector<Vec3b> colorTable(num_labels);
    // background color
    colorTable[0] = Vec3b(0, 0, 0);
    for (int i = 1; i < num_labels; i++) {
        colorTable[i] = Vec3b(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
    }

    // 注意这里的result的类型
    Mat result = Mat::zeros(image.size(), CV_8UC3);
    int w = result.cols;
    int h = result.rows;
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            int label = labels.at<int>(row, col);
            result.at<Vec3b>(row, col) = colorTable[label];
        }
    }
    for (int i = 1; i < num_labels; i++) {
        // 获取中心位置
        int cx = centroids.at<double>(i, 0);
        int cy = centroids.at<double>(i, 1);
        // 获取外接矩形 和面积
        int x = stats.at<int>(i, CC_STAT_LEFT);
        int y = stats.at<int>(i, CC_STAT_TOP);
        int width = stats.at<int>(i, CC_STAT_WIDTH);
        int height = stats.at<int>(i, CC_STAT_HEIGHT);
        // 这个面积的单位是像素
        int area = stats.at<int>(i, CC_STAT_AREA); 
        // 绘制中心位置
        circle(result, Point(cx, cy), 3, Scalar(0, 0, 255), 2, 8, 0);
        // 绘制外接矩形
        Rect box(x, y, width, height);
        rectangle(result, box, Scalar(0, 255, 0), 2, 8, 0);
        putText(result,
            format("%d", area),
            Point(x, y), FONT_HERSHEY_PLAIN, 1.0,
            Scalar(0, 255, 0), 1);
    }
    
    putText(result,
        format("number: %d", num_labels - 1),
        Point(50, 50), FONT_HERSHEY_PLAIN, 1.0,
        Scalar(0, 255, 0), 1);
    imshow("CCL demo", result);
}
