/**
    Opencv example code: accessing mat pixels (binary and rgb images)
    Enrique Marin
    88enrique@gmail.com
*/

#include <stdio.h>
#include <iostream>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

int main(  ){

    // Read the image (grayscale for threshold)
    Mat src = imread("../Images/rgb.png");//, CV_LOAD_IMAGE_GRAYSCALE);
    if (src.empty()){
        printf("No image.\n");
        return -1;
    }

    // Initialize binary mat
    Mat bin;// = Mat(src.rows, src.cols, CV_8SC1);
    threshold(src, bin, 128, 255, CV_THRESH_BINARY);

    // Test size, channels and depth for images
    printf("Size: W: %d, H: %d\n", src.cols, src.rows);
    printf("Channels: %d\n", src.channels());
    printf("Depth: %d\n", src.elemSize());
    printf("Channels: %d\n", bin.channels());
    printf("Depth: %d\n", bin.elemSize());

    // Single-channel image
    if (bin.channels() == 1){
        for (int i=0; i<src.rows; i++){
            for(int j=0; j<src.cols; j++){
                printf("(%d),", bin.at<uchar>(i,j));
            }
            printf("\n\n");
        }
    }
    // 3-Channel image
    else if (bin.channels() == 3){
        for (int i=0; i<bin.rows; i++){
            for(int j=0; j<bin.cols; j++){
                printf("(%d,%d,%d),", bin.at<Vec3b>(i,j)[0], bin.at<Vec3b>(i,j)[1], bin.at<Vec3b>(i,j)[2]);
            }
            printf("\n\n");
        }
    }

    // Show images
    imshow("Binary", bin);
    imshow("RGB", src);

    // Wait for a key
    cvWaitKey(0);

    return 0;
}

