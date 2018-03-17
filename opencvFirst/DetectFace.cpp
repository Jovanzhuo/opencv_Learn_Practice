#include<opencv2/objdetect/objdetect.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2\gpu\gpu.hpp>
#include"EnableSW.h"
using namespace cv;

//人脸检测的类  
CascadeClassifier faceCascade;

#ifdef DETECTFACE

int main()
{
	char key = 0;
	CvCapture *cam = cvCreateCameraCapture(0);
	while (key != 0x1B)
	{
		Mat img = cvQueryFrame(cam);
		cvNamedWindow("frame", 1);
		//imshow("frame", image);

		faceCascade.load("E:\\Programma Study\\openCV\\opencv\\sources\\data\\haarcascades_GPU\\haarcascade_frontalface_alt2.xml");   //加载分类器，注意文件路径  

		//Mat img = imread("E:\\Programma Study\\openCV\\LOL.jpg");
		Mat imgGray;
		vector<Rect> faces;

		if (img.empty())
		{
			return 1;
		}
		if (img.channels() == 3)
		{
			cvtColor(img, imgGray, CV_RGB2GRAY);
		}
		else
		{
			imgGray = img;
		}

		faceCascade.detectMultiScale(imgGray, faces, 1.2, 6, 0, Size(0, 0));   //检测人脸  

		if (faces.size() > 0)
		{
			for (int i = 0; i < faces.size(); i++)
			{
				rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),
					Scalar(0, 0, 255), 1, 8);    //框出人脸位置  
			}
		}

		imshow("frame", img);
		key = waitKey(10);
	}
	//waitKey(0);
	//destroyAllWindows();

	destroyWindow("frame");
	cvReleaseCapture(&cam);
	system("PAUSE");
	return 0;
}

#endif // DETECTFACE