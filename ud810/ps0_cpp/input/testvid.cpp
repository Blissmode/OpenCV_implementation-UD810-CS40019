#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc,char** agrv)
{
    VideoCapture cap("13reasonseclipse.mkv");

    if (cap.isOpened() == false)  
 {
  cout << "Cannot open the video file" << endl;
  cin.get();
  return -1;
 }

 double fps = cap.get(CAP_PROP_FPS); 
 cout << "Frames per seconds : " << fps << endl;

 String window_name = "My First Video";

 namedWindow(window_name, WINDOW_NORMAL); 

 while (true)
 {
  Mat frame;
  bool bSuccess = cap.read(frame);

  if (bSuccess == false) 
  {
   cout << "Found the end of the video" << endl;
   break;
  }

  imshow(window_name, frame);
  if (waitKey(10) == 27)
  {
   cout << "Esc key is pressed by user. Stoppig the video" << endl;
   break;
  }
 }
}