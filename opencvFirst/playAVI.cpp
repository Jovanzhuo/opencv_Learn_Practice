#include<opencv2\highgui\highgui.hpp>
#include<cv.h>
#include"EnableSW.h"
using namespace cv;

int g_slider_position = 0;
CvCapture *g_capture = NULL;

void onTrackbarSlide(int pos)
{
	cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
}

#ifdef PLAYAVI

int main(int argc, char **argv)
{
	cvNamedWindow("PlayAVI", CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture("F:\\Moives\\TAONAIMU\\IPZ-703\\IPZ-703.avi");
	IplImage *frame;
	int frames = (int)cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);
	if (frames != 0)
	{
		cvCreateTrackbar(
			"Position",
			"PlayAVI",
			&g_slider_position,
			frames,
			onTrackbarSlide
		);
	}
	while (1)
	{
		frame = cvQueryFrame(g_capture);
		if (!frame) break;
		cvShowImage("PlayAVI", frame);
		char c = cvWaitKey(33);
		if (c == 0x1B) break;
	}
	cvReleaseCapture(&g_capture);
	cvDestroyWindow("PlayAVI");
	return 0;
}

#endif // PLAYAVI