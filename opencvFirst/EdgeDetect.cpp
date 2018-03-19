#include<cv.h>
#include<highgui.h>

#include "EnableSW.h"

using namespace cv;

#ifdef EDGEDETECT

int main(int argc, char **argv)
{
	IplImage *src = cvLoadImage("..\\resource\\timg.jpg");
	IplImage *dstx_s = cvCreateImage(cvGetSize(src), IPL_DEPTH_16S, src->nChannels);
	IplImage *dstx_u = cvCreateImage(cvGetSize(src), IPL_DEPTH_8S, src->nChannels);

	IplImage *dstS_s = cvCreateImage(cvGetSize(src), IPL_DEPTH_16S, src->nChannels);
	IplImage *dstS_u = cvCreateImage(cvGetSize(src), IPL_DEPTH_8S, src->nChannels);

	IplImage *grayImage = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	IplImage *cannyImage = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);

	if (src != nullptr)
	{
		//1 用于检测块状
		//2 用户检测边缘
		cvLaplace(src, dstx_s, 3);
		cvConvertScale(dstx_s, dstx_u, 1.0, 0);
		cvNamedWindow("raw image", 1);
		cvShowImage("raw image", src);
		cvNamedWindow("Laplace Switch", 1);
		cvShowImage("Laplace Switch", dstx_u);

		//一阶求导，用于检测突变，即边界
		cvSobel(src, dstS_s, 0, 1, 3);
		cvConvertScale(dstS_s, dstS_u, 1.0, 0);
		cvNamedWindow("Sobel Switch", 1);
		cvShowImage("Sobel Switch", dstS_u);

		//用于检测边缘
		cvCvtColor(src, grayImage, CV_BGR2GRAY);
		cvCanny(grayImage, cannyImage, 20, 80, 3);
		cvNamedWindow("Canny Switch", 1);
		cvShowImage("Canny Switch", cannyImage);


		waitKey();
		cvReleaseImage(&src);
		cvReleaseImage(&dstx_s);
		cvReleaseImage(&dstx_u);
		cvReleaseImage(&dstS_s);
		cvReleaseImage(&dstS_u);
	}

	return 0;

}


#endif
