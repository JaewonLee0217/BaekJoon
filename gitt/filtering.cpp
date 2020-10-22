#include "stdafx.h"
#include <math.h>
#include <stdlib.h>>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>

/*
using namespace cv;
using namespace std;

void GrayFilter(Mat& in, Mat& out, int n)
{
	const int FilterSize = 2 * n + 1;
	const int zeroPad = n;
	out= Mat(in.rows + 2* zeroPad, in.cols + 2* zeroPad, CV_8UC1);
	//printf("%d", out.rows);
	//위 패딩 처리
	for (int w = 0; w < out.cols; w++)
	{
		out.at<uchar>(0, w) = 0;
	}
	//왼쪽 패딩 처리
	for (int h = zeroPad; h < out.rows; h++)
	{
		out.at<uchar>(h, 0) = 0;
	}

	//오른쪽 패딩 처리
	for (int h = zeroPad; h < out.rows; h++)
	{
		out.at<uchar>(h, out.rows - zeroPad) = 0;
	}
	//아래 패딩 처리
	for (int w = zeroPad; w < out.cols - zeroPad; w++)
	{
		out.at<uchar>(out.rows - zeroPad, w) = 0;
	}
	//원본데이터 merge
	for (int h = 0; h < in.rows; h++)
	{
		for (int w = 0; w < in.cols; w++)
		{
			out.at<uchar>(h + zeroPad, w + zeroPad) = in.at<uchar>(h, w);
		}
	}
	
}
void RGBFilter(Mat& in, Mat& out2, int n)
{
	const int FilterSize = 2 * n + 1;
	const int zeroPad = n;
	out2 = Mat(in.rows + 2 * zeroPad, in.cols + 2 * zeroPad, CV_8UC3);
	//printf("%d", out2.rows);

	//위 패딩 처리
	for (int w = 0; w < out2.cols; w++)
	{
		out2.at<Vec3b>(0, w) = 0;
	}
	//왼쪽 패딩 처리
	for (int h = zeroPad; h < out2.rows; h++)
	{
		out2.at<Vec3b>(h, 0) = 0;
	}
	//오른쪽 패딩 처리
	for (int h = zeroPad; h < out2.rows; h++)
	{
		out2.at<Vec3b>(h, out2.rows - zeroPad) = 0;
	}
	//아래 패딩 처리
	for (int w = zeroPad; w < out2.cols - zeroPad; w++)
	{
		out2.at<Vec3b>(out2.rows - zeroPad, w) = 0;
	}
	//원본데이터 merge
	for (int h = 0; h < in.rows; h++)
	{
		for (int w = 0; w < in.cols; w++)
		{
			out2.at<Vec3b>(h + zeroPad, w + zeroPad) = in.at<Vec3b>(h, w);
		}
	}
}

int main()
{
	Mat in = imread("lena_gray.jpg", IMREAD_GRAYSCALE);//그레이 데이터 처리
	Mat in2 = imread("Lena_256x256.png", IMREAD_COLOR);//RGB데이터 처리
	Mat out,out2;
	Mat GrayResult1(in.rows,in.cols,CV_8UC1);
	Mat RGBResult1(in2.rows, in2.cols, CV_8UC3);
	Mat GrayResult2(in.rows, in.cols, CV_8UC1);
	Mat RGBResult2(in2.rows, in2.cols, CV_8UC3);
	Mat GrayResult3(in.rows, in.cols, CV_8UC1);
	Mat RGBResult3(in2.rows, in2.cols, CV_8UC3);
	GrayFilter(in,out,1);
	RGBFilter(in2, out2, 1);
	
	
	
	//1. 3x3크기의 moving average 수행(Gray)
	int filterSize = 3 * 3;
	for (int h = 0; h < in.rows;h++)
	{
		for (int w = 0;w < in.cols;w++)
		{
			double Temp = 0.0;
			for (int y = h;y < h + 3;y++)
			{
				for (int x = w;x < w + 3;x++)
				{
					Temp += out.at<uchar>(h, w);
				}
			}
			Temp /= filterSize;
			
			GrayResult1.at<uchar>(h, w) = Temp;
		}
	}
	//1. 3x3크기의 moving average 수행(RGB)
	for (int h = 0; h < in2.rows;h++)
	{
		for (int w = 0;w < in2.cols;w++)
		{
			float TempB = 0.0;
			float TempG = 0.0;
			float TempR = 0.0;
			for (int y = h;y < h + 3;y++)
			{
				for (int x = w;x < w + 3;x++)
				{
					TempB += out2.at<Vec3b>(h, w)[0];
					TempG += out2.at<Vec3b>(h, w)[1];
					TempR += out2.at<Vec3b>(h, w)[2];
				}
			}
			TempB /= filterSize;
			TempG /= filterSize;
			TempR /= filterSize;

			RGBResult1.at<Vec3b>(h, w)[0] = TempB;
			RGBResult1.at<Vec3b>(h, w)[1] = TempG;
			RGBResult1.at<Vec3b>(h, w)[2] = TempR;
		}
	}
	imshow("Q1 Result_gray", GrayResult1);
	imshow("Q1 Result_RGB", RGBResult1);

	//2. Laplacian 수행(Gray)
	int LaplaMask[3][3] = {
		{ 0,1,0 },
		{ 1,-4,1 },
		{ 0,1,0 }
	};
	for (int h = 0; h < in.rows;h++)
	{
		for (int w = 0;w < in.cols;w++)
		{
			int Temp2 = 0;
			for (int y = 0;y < 3;y++)
			{
				for (int x = 0;x < 3;x++)
				{
					Temp2 += out.at<uchar>(h + y, w + x) * LaplaMask[y][x];
				}
			}
			if (Temp2 > 255)
				Temp2 = 255;
			if (Temp2 < 0)
				Temp2 = 0;
			GrayResult2.at<uchar>(h, w) = Temp2;
		}
	}
	//2. Laplacian 수행(RGB)
	for (int h = 0; h < in.rows;h++)
	{
		for (int w = 0;w < in.cols;w++)
		{
			int Temp2B = 0;
			int Temp2G = 0;
			int Temp2R = 0;
			for (int y = 0;y < 3;y++)
			{
				for (int x = 0;x < 3;x++)
				{
					Temp2B += out2.at<Vec3b>(h + y, w + x)[0] * LaplaMask[y][x];
					Temp2G += out2.at<Vec3b>(h + y, w + x)[1] * LaplaMask[y][x];
					Temp2R += out2.at<Vec3b>(h + y, w + x)[2] * LaplaMask[y][x];
				}
			}
			if (Temp2B > 255)
				Temp2B = 255;
			if (Temp2B < 0)
				Temp2B = 0;
			if (Temp2G > 255)
				Temp2G = 255;
			if (Temp2G < 0)
				Temp2G = 0;
			if (Temp2R > 255)
				Temp2R = 255;
			if (Temp2R < 0)
				Temp2R = 0;
			RGBResult2.at<Vec3b>(h, w)[0] = Temp2B;
			RGBResult2.at<Vec3b>(h, w)[1] = Temp2G;
			RGBResult2.at<Vec3b>(h, w)[2] = Temp2R;
		}
	}
	imshow("Q2 Result_Gray", GrayResult2);
	imshow("Q2 Result_RGB", RGBResult2);

	//3. Sharpening filter 구현(Gray)
	int shMask[3][3] = {
		{ 0,-1,0 },
		{ -1,5,-1 },
		{ 0,-1,0 }
	};
	for (int h = 0; h < in.rows;h++)
	{
		for (int w = 0;w < in.cols;w++)
		{
			int Temp3 = 0.0;
			for (int y = 0;y < 3;y++)
			{
				for (int x = 0;x < 3;x++)
				{
					Temp3 += out.at<uchar>(h + y, w + x)* shMask[y][x];
				}
			}
			if (Temp3 > 255)
				Temp3 = 255;
			if (Temp3 < 0)
				Temp3 = 0;
			GrayResult3.at<uchar>(h, w) = Temp3;
		}
	}
	//3. Sharpening filter 구현(RGB)
	for (int h = 0; h < in.rows;h++)
	{
		for (int w = 0;w < in.cols;w++)
		{
			int Temp3B = 0;
			int Temp3G = 0;
			int Temp3R = 0;
			for (int y = 0;y < 3;y++)
			{
				for (int x = 0;x < 3;x++)
				{
					Temp3B += out2.at<Vec3b>(h + y, w + x)[0] * shMask[y][x];
					Temp3G += out2.at<Vec3b>(h + y, w + x)[1] * shMask[y][x];
					Temp3R += out2.at<Vec3b>(h + y, w + x)[2] * shMask[y][x];
				}
			}
			if (Temp3B > 255)
				Temp3B = 255;
			if (Temp3B < 0)
				Temp3B = 0;
			if (Temp3G > 255)
				Temp3G = 255;
			if (Temp3G < 0)
				Temp3G = 0;
			if (Temp3R > 255)
				Temp3R = 255;
			if (Temp3R < 0)
				Temp3R = 0;
			RGBResult3.at<Vec3b>(h, w)[0] = Temp3B;
			RGBResult3.at<Vec3b>(h, w)[1] = Temp3G;
			RGBResult3.at<Vec3b>(h, w)[2] = Temp3R;
		}
	}
	imshow("Q3 Result_gray", GrayResult3);
	imshow("Q3 Result_RGB", RGBResult3);
	waitKey(0);
	return 0;

}
*/