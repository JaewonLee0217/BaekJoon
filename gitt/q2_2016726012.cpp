#include "stdafx.h"
#include <math.h>

#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
/*
using namespace cv;
using namespace std;
//RGB를 YUV로 변환하는 코드
int main()
{
	Mat img_in = imread("Camera_2016726012.jpg"); //카메라 이미지 읽고
	Mat OutYUV(img_in.rows, img_in.cols, CV_8UC3);
	Mat yuvImg;
	Mat OutY(img_in.rows, img_in.cols, CV_8UC1);
	Mat OutU(img_in.rows, img_in.cols, CV_8UC1);
	Mat OutV(img_in.rows, img_in.cols, CV_8UC1);
	//YUV변수 선언
	unsigned char** Y;
	unsigned char** U;
	unsigned char** V;

	cvtColor(img_in, yuvImg, CV_RGB2YUV);
	unsigned char* pDataRGB = img_in.data;
	imshow("Using cvtcolor", yuvImg);
	//메모리 할당
	Y = new unsigned char* [img_in.rows];
	U = new unsigned char* [img_in.rows];
	V = new unsigned char* [img_in.rows];
	for (int h = 0;h < img_in.rows;h++)
	{
		Y[h] = new unsigned char[img_in.cols];
		U[h] = new unsigned char[img_in.cols];
		V[h] = new unsigned char[img_in.cols];
	}
	//변환
	for (int row = 0; row < img_in.rows; row++)
	{
		for (int col = 0; col < img_in.cols; col++)
		{
			uchar b, g, r;
			b = pDataRGB[row * img_in.cols * 3 + col * 3];
			g = pDataRGB[row * img_in.cols * 3 + col * 3 + 1];
			r = pDataRGB[row * img_in.cols * 3 + col * 3 + 2];
			Y[row][col] = (0.299 * r) + (0.587 * g) + (0.114 * b)+16;
			U[row][col] = (-0.169 * r) + (-0.331 * g) + (0.499 * b)+128;
			V[row][col] = (0.499 * r) - (0.418 * g) - (0.081 * b)+128;
		}
	}
	
	//merge
	for (int y = 0; y < img_in.rows;y++)
	{
		for (int x = 0; x < img_in.cols;x++)
		{
			OutYUV.at<Vec3b>(y, x)[0] = Y[y][x];
			OutYUV.at<Vec3b>(y, x)[1] = U[y][x];
			OutYUV.at<Vec3b>(y, x)[2] = V[y][x];
		}
	}
	//cvtColor(OutYUV, OutYUV, CV_YUV2RGB);


	imshow("by Writing mycode", OutYUV);
	//YUV파일로 저장
	
	
	
	//2D메모리 해제
	for (int n = 0;n < img_in.rows;n++) {
		delete[] Y[n];
		delete[] U[n];
		delete[] V[n];
	}
	delete[] Y;
	delete[] U;
	delete[] V;
	

	

	waitKey(0);

	return 0;
}
*/