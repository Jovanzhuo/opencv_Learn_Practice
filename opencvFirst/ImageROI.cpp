#include<cv.h>
#include<highgui.h>
#include<iostream>
#include "EnableSW.h"

using namespace std;
using namespace cv;

#ifdef  IMAGEROI

int main(int argc, char **argv)
{
	IplImage* src;
	src = cvLoadImage("..\\resource\\cat.jpg");
	if (src != nullptr)
	{
		int x = 840;
		int y = 40;
		int width = 256;
		int height = 256;
		int add = 150;
		cvSetImageROI(src, cvRect(x, y, width, height));
		cvAddS(src, cvScalar(add), src);
		cvResetImageROI(src);
		cvNamedWindow("roi_add", 1);
		cvShowImage("roi_add", src);
		cvWaitKey();
	}
	return 0;
}

#endif //  ImageROI
