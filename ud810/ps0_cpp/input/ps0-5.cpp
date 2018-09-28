#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat img=imread("../output/lena.png"),img2;
    imshow("diaz input",img);
    waitKey(0);
    img2=img;
    int x=1,sigmax=0,sigmay=0;

    
    while(true)
    {
    if(x%2)
      {
          vector <Mat> vecto(3);
        split(img2,vecto);
        GaussianBlur(vecto[2],vecto[2],Size(x,x),sigmax,sigmay);  // Have the index as 0,1,2 for blue, greem and red respectively 
        createTrackbar("Kernal size","Gaussian diaz",&x,50);
        createTrackbar("sigma x","Gaussian diaz",&sigmax,50);
        createTrackbar("sigma y","Gaussian diaz",&sigmay,50);
        merge(vecto,img);
        imshow("Gaussian diaz",img);
      }
      int press=waitKey(50);
      if(press==27)
      break;
    }
   /* Uncomment to check out working of Unsharp Mask 
    
        int x=11;

        GaussianBlur(img,img2,Size(x,x),0,0);
        imshow("Gaussian diaz",img2);
        createTrackbar("size of i","Gaussian diaz",&x,55);

         while(true)
      {
          if(x%2)
        {GaussianBlur(img,img2,Size(x,x),0,0);
        imshow("Gaussian diaz",img2);
        Mat UnsharpMask=img-img2;
        imshow("Unsharp Mask",UnsharpMask);
        Mat sharp=img+UnsharpMask;
        imshow("Sharpened image",sharp);
        }
        int press=waitKey(50);

        if(press==27)
        break;
      }*/
    destroyAllWindows();
}
