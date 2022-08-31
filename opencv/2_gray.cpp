#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
    string imgpath = cv::samples::findFile("img.jpg");
    cv::Mat colorimg = cv::imread(imgpath, cv::IMREAD_COLOR);
    if(colorimg.empty())
    {
        cout << "Error opening: " << imgpath <<  endl;
        return 1;
    }
    
    cout << colorimg.rows << 'x' << colorimg.cols << endl;
    
    uint8_t *buf = (uint8_t *)colorimg.data;
    cout << endl << "color: ";
    for (int i = 0; i < 40; i++) {
      int ival = buf[i];
      cout << ival << ", ";
    }
    cout << endl;

    cv::Mat grayimg(colorimg.rows, colorimg.cols, CV_8UC3);
    
    // make img gray
    int stride = 3;
    for (int y = 0; y < colorimg.rows; y++) {
      for (int x = 0; x < colorimg.cols; x++) {
        int ii = stride*(y*colorimg.cols + x);
        int b = buf[ii + 0];
        int g = buf[ii + 1];
        int r = buf[ii + 2];

        float grayFloat = 0.2126*r + 0.7152*g + 0.0722*b;
        uint8_t gray = (uint8_t) grayFloat;
        
        grayimg.data[ii + 0] = gray;
        grayimg.data[ii + 1] = gray;
        grayimg.data[ii + 2] = gray;
        
      }
    }

    cout << endl << "gray: ";
    for (int i = 0; i < 40; i++) {
      int ival = grayimg.data[i];
      cout << ival << ", ";
    }
    cout << endl;

    cv::imshow("Gray", grayimg);
    int k = cv::waitKey(0);
    return 0;
}

