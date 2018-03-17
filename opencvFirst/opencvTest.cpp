#include <opencv2\opencv.hpp>
#include <cv.h>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

//盐噪点，img为输入图像，saltNum为噪点个数
void salt(Mat &img, int saltNum)
{
	int x, y;
	int i;
	for (i = 0; i < saltNum; i++)
	{
		x = rand() % img.cols;
		y = rand() % img.rows;

		if (img.channels() == 1)
		{
			img.at<uchar>(y, x) = 255;
		}
		else if (img.channels() == 3)
		{
			img.at<Vec3b>(y, x)[0] = 255;
			img.at<Vec3b>(y, x)[1] = 255;
			img.at<Vec3b>(y, x)[2] = 255;
		}
	}
}

//椒噪点，img为输入图像，pepperNum为噪点个数
void pepper(Mat &img, int pepperNum)
{
	int x, y;
	int i;
	for (i = 0; i < pepperNum; i++)
	{
		x = rand() % img.cols;
		y = rand() % img.rows;

		if (img.channels() == 1)
		{
			img.at<uchar>(y, x) = 0;
		}
		else if (img.channels() == 3)
		{
			img.at<Vec3b>(y, x)[0] = 0;
			img.at<Vec3b>(y, x)[1] = 0;
			img.at<Vec3b>(y, x)[2] = 0;
		}
	}
}

//int main()
//{
//	Mat src = imread("E:\\Programma Study\\openCV\\zaosheng.jpg");
//	Mat dst;
//	
//	salt(src, 1000);
//	pepper(src, 1000);
//	imshow("加椒盐噪点", src);
//	waitKey();
//
//	//高斯滤波
//	//src:输入图像
//	//dst:输出图像
//	//Size(5,5)模板大小，为奇数
//	//x方向方差
//	//Y方向方差
//	GaussianBlur(src, dst, Size(5, 5), 0, 0);
//	imwrite("gauss.jpg", dst);
//	imshow("高斯滤波", dst);
//	waitKey();
//
//	//中值滤波
//	//src:输入图像
//	//dst::输出图像
//	//模板宽度，为奇数
//	medianBlur(src, dst, 3);
//	imwrite("med.jpg", dst);
//	imshow("中值滤波", dst);
//	waitKey();
//
//	//均值滤波
//	//src:输入图像
//	//dst:输出图像
//	//模板大小
//	//Point(-1,-1):被平滑点位置，为负值取核中心
//	blur(src, dst, Size(3, 3), Point(-1, -1));
//	imwrite("mean.jpg", dst);
//	imshow("均值滤波", dst);
//	waitKey();
//
//	//双边滤波
//	//src:输入图像
//	//dst:输入图像
//	//滤波模板半径
//	//颜色空间标准差
//	//坐标空间标准差
//	bilateralFilter(src, dst, 5, 10.0, 2.0);
//	imwrite("bilateral.jpg", dst);
//	imshow("双边滤波", dst);
//	waitKey();
//
//	return 0;
//
//}