#include <cv.h>
#include <highgui.h>
#include <iostream>
#include "EnableSW.h"

using namespace std;
using namespace cv;

#ifdef CONNECTEDDOMAIN

int main(int argc, char** argv)
{
	IplImage *src = cvLoadImage("..\\resource\\plate2.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);
	IplImage *rec_src = cvCreateImage(cvGetSize(src), 8, 1);
	Mat matdst;
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contour = 0;

	GaussianBlur(cvarrToMat(src), matdst, Size(5, 5), 0, 0);
	src = cvCloneImage(&IplImage(matdst));
	cvThreshold(src, src, 200, 255, CV_THRESH_BINARY);
	cvNamedWindow("RawSource", 1);
	cvShowImage("RawSource", src);
	cvCopy(src, rec_src);

	int contour_num = cvFindContours(src, storage, &contour, sizeof(CvContour), CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	cvZero(dst);
	CvSeq *_contour = contour;
	double maxarea = 0;
	double minarea = 500;
	int m = 0;
	for (; contour != 0; contour = contour->h_next)
	{
		double temparea = fabs(cvContourArea(contour));
		if (temparea < minarea)
		{
			cvSeqRemove(contour, 0);
			continue;
		}
		CvRect arect = cvBoundingRect(contour, 0);
		if (temparea > maxarea)
			maxarea = temparea;
		m++;
		CvScalar color = CV_RGB(0, 255, 255);
		cvDrawContours(dst, contour, color, color, -1, 1, 8);
		cvRectangle(rec_src, cvPoint(arect.x, arect.y), cvPoint(arect.x + arect.width, arect.y + arect.height), color);
	}
	//contour = _contour;
	//int count = 0;
	//for (; contour != 0; contour = contour->h_next)
	//{
	//	count++;
	//	double temparea = fabs(cvContourArea(contour));
	//	if (temparea == maxarea && maxarea > 0)
	//	{
	//		CvScalar color = CV_RGB(255, 0, 0);
	//		cvDrawContours(dst, contour, color, color, -1, 1, 8);
	//	}
	//}
	//printf
	//cout << m << endl;
	cvNamedWindow("Source", 1);
	cvShowImage("Source", rec_src);
	cvNamedWindow("components", 1);
	cvShowImage("components", dst);
	cvWaitKey(0);
	cvDestroyAllWindows();
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	return 0;
}

#endif // CONNECTEDDOMAIN