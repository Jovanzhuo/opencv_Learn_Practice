#include <opencv2\opencv.hpp>
#include <cv.h>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

//����㣬imgΪ����ͼ��saltNumΪ������
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

//����㣬imgΪ����ͼ��pepperNumΪ������
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
//	imshow("�ӽ������", src);
//	waitKey();
//
//	//��˹�˲�
//	//src:����ͼ��
//	//dst:���ͼ��
//	//Size(5,5)ģ���С��Ϊ����
//	//x���򷽲�
//	//Y���򷽲�
//	GaussianBlur(src, dst, Size(5, 5), 0, 0);
//	imwrite("gauss.jpg", dst);
//	imshow("��˹�˲�", dst);
//	waitKey();
//
//	//��ֵ�˲�
//	//src:����ͼ��
//	//dst::���ͼ��
//	//ģ���ȣ�Ϊ����
//	medianBlur(src, dst, 3);
//	imwrite("med.jpg", dst);
//	imshow("��ֵ�˲�", dst);
//	waitKey();
//
//	//��ֵ�˲�
//	//src:����ͼ��
//	//dst:���ͼ��
//	//ģ���С
//	//Point(-1,-1):��ƽ����λ�ã�Ϊ��ֵȡ������
//	blur(src, dst, Size(3, 3), Point(-1, -1));
//	imwrite("mean.jpg", dst);
//	imshow("��ֵ�˲�", dst);
//	waitKey();
//
//	//˫���˲�
//	//src:����ͼ��
//	//dst:����ͼ��
//	//�˲�ģ��뾶
//	//��ɫ�ռ��׼��
//	//����ռ��׼��
//	bilateralFilter(src, dst, 5, 10.0, 2.0);
//	imwrite("bilateral.jpg", dst);
//	imshow("˫���˲�", dst);
//	waitKey();
//
//	return 0;
//
//}