/*
*reference:http://blog.csdn.net/wangxuwen2/article/details/52175063
*/
#include<cv.h>
#include<highgui.h>
#include"EnableSW.h"

using namespace cv;

#ifdef IMAGEFFTANALYZE
int main()
{
	Mat srcImage = imread("..\\resource\\timg.jpg", 0);
	if (!srcImage.data) { printf("There is something wrong when reading the image! \n"); return -1; }
	imshow("srcImage", srcImage);

	//broaden the srcImage  
	int m = getOptimalDFTSize(srcImage.rows);
	int n = getOptimalDFTSize(srcImage.cols);
	Mat padded;
	copyMakeBorder(srcImage, padded, 0, m - srcImage.rows, 0, n - srcImage.cols, BORDER_CONSTANT, Scalar::all(0));

	//prepare some memory room for DFT  
	Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);

	//DFT  
	dft(complexI, complexI);

	//�Ѹ���ת��Ϊ��ֵ ȡģ 
	split(complexI, planes);
	magnitude(planes[0], planes[1], planes[0]);
	Mat magnitudeImage = planes[0];

	//���ж����߶�����  �˴���1��Ϊ�˽�(0,1)��������ֵ�Ķ���������ֵ
	magnitudeImage += Scalar::all(1);
	log(magnitudeImage, magnitudeImage);

	//���� & �طֲ�����ͼ����  
	magnitudeImage = magnitudeImage(Rect(0, 0, magnitudeImage.cols & -2, magnitudeImage.rows & -2));

	int cx = magnitudeImage.cols / 2;
	int cy = magnitudeImage.rows / 2;
	Mat q0 = magnitudeImage(Rect(0, 0, cx, cy));
	Mat q1 = magnitudeImage(Rect(cx, 0, cx, cy));
	Mat q2 = magnitudeImage(Rect(0, cy, cx, cy));
	Mat q3 = magnitudeImage(Rect(cx, cy, cx, cy));

	Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);

	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);

	normalize(magnitudeImage, magnitudeImage, 0, 1, NORM_MINMAX);

	imshow("Ƶ��ֵͼ", magnitudeImage);
	waitKey();

	return 0;
}

#endif // IMAGEFFTANALYZE
