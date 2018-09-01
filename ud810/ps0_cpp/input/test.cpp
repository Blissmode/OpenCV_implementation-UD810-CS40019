#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat image= imread("../output/diaz.jpg");
    if(image.empty())
    {
        cout<<"Could not find the required image"<<endl;
        cin.get();
        return -1;
    }

    cout<<image.rows<<" "<<image.cols<<endl;
    string window="Cameron Diaz is <3";
    namedWindow(window);
    imshow(window,image);
    waitKey(0);
    Mat vecto[3];
    split(image,vecto);
    imshow("Blue plane",vecto[0]);
    imshow("Green plane",vecto[1]);
    imshow("Red plane",vecto[2]);

    for(int i=0;i<image.rows;i++)
    {
        for(int j=0;j<image.cols;j++)
        {
            int t;
            t=image.at<Vec3b>(i,j)[0];
            image.at<Vec3b>(i,j)[0]=image.at<Vec3b>(i,j)[2];
            image.at<Vec3b>(i,j)[2]=t;
        }
    }

    imshow("Swapped image",image);

    // split(image,vecto);
    // imshow("Blue plane of Swapped image",vecto[0]);

    waitKey(0);
    destroyWindow(window);
    int startX=200,startY=200,width=100,height=100;

    Mat ROI(image, Rect(startX,startY,width,height));       // For cropping Images, Adult discretition required :P
    Mat croppedImage;
    ROI.copyTo(croppedImage);
    imshow("Cropped portion",croppedImage);
    waitKey(0);
    destroyWindow(window);
}

