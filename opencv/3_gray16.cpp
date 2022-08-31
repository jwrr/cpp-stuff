#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstdint>
using namespace std;
int main()
{

    // ========================================================================
    // READ IMAGE

    string imgpath = cv::samples::findFile("img.jpg");
    cv::Mat colorimg = cv::imread(imgpath, cv::IMREAD_COLOR);
    if(colorimg.empty())
    {
        cout << "Error opening: " << imgpath <<  endl;
        return 1;
    }
    
    cout << colorimg.rows << 'x' << colorimg.cols << endl;

    // ========================================================================
    // SHOW SOME BYTES OF THE IMAGE. When image is all red you will see:
    //    0, 0, 255, 0, 0, 255 ,,, This means BGR are in adjacent bytes, not
    // separate blue aray, green array, red array.
    
      uint8_t *colorbuf = (uint8_t *)colorimg.data;
      cout << endl << "color: ";
      for (int i = 0; i < 40; i++) {
        int val = colorbuf[i];
        cout << val << ", ";
      }
      cout << endl;


    // ========================================================================
    // CONVERT COLOR TO GRAY16 (CV_16UC1)

    cv::Mat gray16(colorimg.rows, colorimg.cols, CV_16UC1);
    uint16_t *gray16_buf = (uint16_t *)gray16.data;
    int stride = 3; // stride is 3 for blue byte, green byte and red byte
    for (int y = 0; y < gray16.rows; y++) {
      for (int x = 0; x < gray16.cols; x++) {
        
        int ii = y*colorimg.cols + x;
        int iii = stride*ii;
        uint8_t b = colorbuf[iii + 0]; // colorbuf is same as colorimg.data
        uint8_t g = colorbuf[iii + 1];
        uint8_t r = colorbuf[iii + 2];

        float grayFloat = 256.0 * (0.2126*r + 0.7152*g + 0.0722*b);
        uint16_t gray = (uint16_t) grayFloat;
        gray16_buf[ii] = gray;
      }
    }
    
    cout << endl << "gray16: ";
    for (int i = 0; i < 40; i++) {
      int val = gray16_buf[i];
      cout << val << ", ";
    }
    cout << endl;

    // ========================================================================
    // APPLY SCALE and OFFSET (just doing something to the image)
    // Also find min and max value.
    
    cv::Mat corrected16(gray16.rows, gray16.cols, CV_16UC1);
    uint16_t *corrected16_buf = (uint16_t *)corrected16.data;
    uint16_t corrected_min = 0xFFFF;
    uint16_t corrected_max = 0x0000;
    for (int y = 0; y < gray16.rows; y++) {
      for (int x = 0; x < gray16.cols; x++) {
        
        int ii = y*gray16.cols + x;
        uint16_t val = gray16_buf[ii];
        float corrected_val_float = val * 0.9 + 25; // dummy scale and offset
        uint16_t corrected_val = (uint16_t)corrected_val_float;
        corrected16_buf[ii] = corrected_val; // corrected16_buf is the same as corrected16.data
        if (corrected_val < corrected_min) {
          corrected_min = corrected_val;
        }
        if (corrected_val > corrected_max) {
          corrected_max = corrected_val;
        }
        
      }
    }


    cout << endl << "corrected16: ";
    for (int i = 0; i < 40; i++) {
      int val = corrected16_buf[i];
      cout << val << ", ";
    }
    cout << endl;
    cout << "Min: " << corrected_min << " Max: " << corrected_max << endl;



    // ========================================================================
    // APPLY LINEAR GAIN
    
    cv::Mat linear16(corrected16.rows, corrected16.cols, CV_16UC1);
    uint16_t *linear_buf16 = (uint16_t *)linear16.data;
    float rise = 64 * 1024;
    float run = corrected_max - corrected_min;
    float slope = rise / run; 
    for (int y = 0; y < corrected16.rows; y++) {
      for (int x = 0; x < corrected16.cols; x++) {
        int ii = y*corrected16.cols + x;
        uint16_t val = corrected16_buf[ii];
        float val_float = slope * (val - corrected_min);
        uint16_t val_enhanced = (uint16_t)val_float;
        linear_buf16[ii] = val_enhanced; // this is the same as assigning linear16.data[ii]
      }
    }

    cout << endl << "linear16: ";
    for (int i = 0; i < 40; i++) {
      int val = linear_buf16[i];
      cout << val << ", ";
    }
    cout << endl;
    cout << "slope: " << slope << " Run: " << run << endl;

    
    // ========================================================================
    // CONVERT 16-BIT MONO TO 8-BIT BGR GRAY

    cv::Mat gray8(linear16.rows, linear16.cols, CV_8UC3);
    uint8_t *buf8_gray = (uint8_t *)gray8.data;
    stride = 3; // stride is 1 for BGR
    for (int y = 0; y < linear16.rows; y++) {
      for (int x = 0; x < linear16.cols; x++) {
        
        int ii = y*linear16.cols + x;
        uint16_t val16 = linear_buf16[ii] >> 8;
        uint8_t val8 = (uint8_t)val16;
        
        int iii = stride*ii;
        buf8_gray[iii + 0] = val8; // buf8_gray is same as gray8.data
        buf8_gray[iii + 1] = val8;
        buf8_gray[iii + 2] = val8;
      }
    }
    
    cout << endl << "gray: ";
    for (int i = 0; i < 40; i++) {
      int ival = gray8.data[i];
      cout << ival << ", ";
    }
    cout << endl;


    // ========================================================================
    // SHOW THE IMAGE

    cv::imshow("Gray", gray8);
    int k = cv::waitKey(0);
    return 0;
}

