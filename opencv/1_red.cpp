#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
    string image_path = cv::samples::findFile("red.png");
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    if(img.empty())
    {
        cout << "Error opening: " << image_path <<  endl;
        return 1;
    }
    
    cout << img.rows << 'x' << img.cols << endl;
    
    uint8_t *buf = (uint8_t *)img.data;
    for (int i = 0; i < 40; i++) {
      int ival = buf[i];
      cout << ival << ", ";
    }
    cout << endl;
    
    
    cv::imshow("Red", img);
    int k = cv::waitKey(0);
    if(k == 's')
    {
        cv::imwrite("red2.png", img);
    }
    return 0;
}

