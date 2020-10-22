
#include "stdafx.h"
#include <math.h>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
/*

using namespace cv;
using namespace std;

//(x,y)���� (px,py)�� roatate������ �� 
//px = xcos@-ysin@
//py = xsin@-ycos@



int main()
{
	int x;
	printf("ȸ����ų ���� x�� �Է��Ͻÿ�. ");
	cin >> x;
	Mat img_in = imread("Lena_256x256.png");
	cvtColor(img_in, img_in, COLOR_RGB2GRAY);
	namedWindow("Original_Gray_Image", WINDOW_AUTOSIZE);
	imshow("Original_Gray_Image", img_in);
	//������� ���� ���� Ȯ��.

	//ȸ�� ����
	double PI = 3.141592;
	double theta = (PI * x) / 180.0;

	int height = img_in.rows;
	int width = img_in.cols;

	//�߰� ��ǥ ����
	double center_x = width / 2.0;
	double center_y = height / 2.0;

	Mat img_out(width, height, CV_8UC1, Scalar(0));

	for (int i = 0; i < height - 1; i++)
	{
		for (int j = 0; j < width - 1; j++)
		{
			int px = center_x + (j - center_x) * cos(theta) + (i - center_y) * sin(theta);
			int py = center_y + (i - center_y) * cos(theta) - (j - center_x) * sin(theta);

			if ((px >= 0 && px < width) && (py >= 0 && py < height))
			{
				img_out.at<uchar>(i, j) = img_in.at<uchar>(py, px);
			}
		}
	}
	imshow("Rotated Image", img_out);

	
	waitKey(0);

	return 0;

}

*/