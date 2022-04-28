#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace std;
using namespace dnn;


int main(int argc, char** argv)
{
    string bin_model = "f:/ai/OpenCV_DNN_data/bvlc_googlenet.caffemodel";
    string protxt = "f:/ai/OpenCV_DNN_data/bvlc_googlenet.prototxt";

    //load DNN model
    Net net = readNetFromCaffe(protxt, bin_model);

    // ���ü����̨
    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    net.setPreferableTarget(DNN_TARGET_CPU);

    // ��ȡ������Ϣ
    vector<string> layer_names = net.getLayerNames();
    for (int i = 0; i < layer_names.size(); i++) {
        int id = net.getLayerId(layer_names[i]);
        auto layer = net.getLayer(id);
        printf("layer id: %d, type: %s, name: %s\n", id, layer->type.c_str(), layer->name.c_str());
    }

    Mat src = imread("f:/imaegs/apple.jpg");
    imshow("input", src);

    // ��������
    Mat rgb;
    cvtColor(src, rgb, COLOR_BGR2RGB);
    int w = 224;
    int h = 224;
    Mat inputBlob = blobFromImage(src, 1.0, Size(w, h), Scalar(117.0, 117.0, 117.0), true, false);
    // ��������
    net.setInput(inputBlob);
    // �ƶ�
    Mat probMat = net.forward("prop");
    // �������
    Mat prob = probMat.reshape(1, 1);
    Point classNum;
    double classProb;
    minMaxLoc(prob, NULL, &classProb, NULL, &classNum);
    int index = classNum.x;
    printf("\n current index = %d, possible: %.2f", index, classProb);

    waitKey(0);
    destroyAllWindows();
    return 0;
}


