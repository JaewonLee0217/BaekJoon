#include "stdafx.h"
#include <math.h>
#include <stdlib.h>>
#include <opencv/cv.h>
//#include "afxdialogex.h"
#include <opencv2/opencv.hpp>
#include <time.h>

using namespace std;
using namespace cv;

void saltpepper(Mat& img, int n);
double getPSNR(unsigned char** Ori, unsigned char** Dst, int Height, int Width);

int main()
{
	float  arr[256 * 256];
	FILE* file1 = fopen("lena256.raw", "rb");
	//fread(arr, 256 * 256, 1, file1);
	//Mat before(256, 256, CV_8UC1, arr);
	//imshow("Before", before);
	//saltpepper(before, 1000);
	//imshow("AFter", before);

	return 0;
}
double getPSNR(unsigned char** Ori, unsigned char** Dst, int Height, int Width)
{
	double MSE = 0;
	for (int h = 0;h < Height;h++)
	{
		for (int w = 0;w < Width;w++)
		{
			MSE += (Ori[h][w] - Dst[h][w]) * (Ori[h][w] - Dst[h][w]);
		}
	}
	MSE /= (Height * Width);
	double PSNR = 10 * log10((255 * 255) / MSE);

	return PSNR;

}

void saltpepper(Mat& img, int n)
{
	int a, b;
	srand((int)time(NULL));
	for (int k = 0;k < n;k++)
	{
		a = rand() % img.cols;
		b = rand() % img.rows;
		int sp = (rand() % 2) * 255; //0또는 255할당
		img.at<uchar>(a, b) = sp;
	}
}