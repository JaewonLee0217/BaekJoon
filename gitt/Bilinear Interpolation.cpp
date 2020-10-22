
#include "stdafx.h"
#include <math.h>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
/*
using namespace cv;
using namespace std;

//Bilinear Interpolation 방법을 이용하여, 256x256 크기의 영상을
//임의의 크기(x_size, y_size)로 바꾸는 함수.
void BilinearInterpolation(Mat& in, int x_size, int y_size);

int main() {
	//0. testcase 436,512
	//1. 256x256크기의 영상을 읽고 Gray로 바꾸기
	Mat img_in = imread("Lena_256x256.png");
	cvtColor(img_in, img_in, COLOR_RGB2GRAY);
	namedWindow("Original_Gray_Image", WINDOW_AUTOSIZE);
	imshow("Original_Gray_Image", img_in);
	printf("Origina Image's width= %d \n", img_in.cols);
	printf("Origina Image's height= %d \n", img_in.rows);
	//2. case1->436x436으로 확대
	//BilinearInterpolation(img_in,  436, 436);
	//3. case2->512x512으로 확대
	printf("Scaling x2---->\n");
	BilinearInterpolation(img_in,  512, 512);

	waitKey(0);
	return 0;
}
void BilinearInterpolation(Mat& in, int x_size, int y_size)
{
	//값 초기화.
	int height = 0;
	int width = 0;
	double h_rate = 0;
	double w_rate = 0;

	height = y_size;
	width = x_size;
	//거리비로 Pn간의 연산을 진행하므로 각각rate를 정의.
	h_rate = (double)height / (double)in.rows;
	w_rate = (double)width / (double)in.cols;
	//만들어줄 이미지 인스턴스 생성, type은 그레이이므로 1channel.
	Mat out(height, width, CV_8UC1, Scalar(0));


	for (int y = 0; y < out.rows - 1; y++) 
	{
		for (int x = 0; x < out.cols - 1; x++) 
		{
			int px = (int)(x / w_rate);
			int py = (int)(y / h_rate);
			//기존 px가 원본 픽셀의 높이, 너비보다 1이상 차이가 날 경우, break
			if (px >= in.cols - 1 || py >= in.rows - 1)
			{
				break;
			}
			double fx1 = (double)x / (double)w_rate - (double)px;
			double fx2 = 1 - fx1;
			double fy1 = (double)y / (double)h_rate - (double)py;
			double fy2 = 1 - fy1;

			double w1 = fx2 * fy2;
			double w2 = fx1 * fy2;
			double w3 = fx2 * fy1;
			double w4 = fx1 * fy1;
			//channel이 1이므로.
			uchar p1 = in.at<uchar>(py, px);
			uchar p2 = in.at<uchar>(py, px + 1);
			uchar p3 = in.at<uchar>(py + 1, px);
			uchar p4 = in.at<uchar>(py + 1, px + 1);
			out.at<uchar>(y, x) = (w1 * p1) +( w2 * p2) + (w3 * p3) + (w4 * p4);
		}
	}
	printf("Converted Image's width= %d \n", out.cols);
	printf("Converted Image's height= %d \n", out.rows);
	namedWindow("Converted Image", WINDOW_AUTOSIZE);
	imshow("Converted Image", out);
	
	
	
}

*/