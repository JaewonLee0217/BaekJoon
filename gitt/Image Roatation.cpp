
#include "stdafx.h"
#include <math.h>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
/*

using namespace cv;
using namespace std;

//(x,y)에서 (px,py)로 roatate돌렸을 때 
//px = xcos@-ysin@
//py = xsin@-ycos@



int main()
{
	int x;
	printf("회전시킬 각도 x를 입력하시오. ");
	cin >> x;
	Mat img_in = imread("Lena_256x256.png");
	cvtColor(img_in, img_in, COLOR_RGB2GRAY);
	namedWindow("Original_Gray_Image", WINDOW_AUTOSIZE);
	imshow("Original_Gray_Image", img_in);
	//여기까지 원본 영상 확인.

	//회전 각도
	double PI = 3.141592;
	double theta = (PI * x) / 180.0;

	int height = img_in.rows;
	int width = img_in.cols;

	//중간 좌표 설정
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