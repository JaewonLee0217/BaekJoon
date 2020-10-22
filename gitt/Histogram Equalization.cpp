#include "stdafx.h"
#include <math.h>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
//#include <Windows.h>
/*
using namespace cv;
using namespace std;

unsigned char** MemAlloc2D(int nHeight, int nWidth) {
	unsigned char** rtn = new unsigned char* [nHeight];
	for (int i = 0; i < nHeight;i++)
	{
		rtn[i] = new unsigned char[nWidth];
		memset(rtn[i], 0, sizeof(unsigned char) * nWidth);
	}
	return rtn;
}

void MemFree2D(unsigned char** Mem, int nHeight) {
	for (int i = 0; i < nHeight;i++)
	{
		delete[] Mem[i];
	}
	delete[] Mem;
}

void getHistogram(int nHeight, int nWidth, unsigned char** ch_in_gray, int* Hist)
{
	if (Hist == NULL) {
		Hist = new int[256];
		memset(Hist, 0, sizeof(int) * 256);
		for (int h = 0;h < nHeight;h++)
		{
			for (int w = 0; w < nWidth; w++)
			{
				Hist[ch_in_gray[h][w]]++;
			}
		}

	}
	//Normalize 히스토
	int nMax = 0;
	for (int i = 0;i < 256;i++)
	{
		if (nMax < Hist[i])
		{
			nMax = Hist[i];
		}
	}
	double dNormalizeFactor = 255.0 / nMax;

	//Display 히스토 스램
	Mat HistDisp = Mat(256, 256, CV_8UC1);
	HistDisp = Scalar::all(0);

	for (int w = 0;w < 256;w++)
	{
		int nNormalValue = (int)Hist[w] * dNormalizeFactor;
		for (int h = 255; h > 255 - nNormalValue;h--)
		{
			HistDisp.at<unsigned char>(h, w) = 255;
		}
	}
	imshow("Histogram", HistDisp);
	waitKey(0);
}

void HistogramEqualization(int nHeight, int nWidth, unsigned char** ch_in_gray, int* Hist);
int main()
{
	int nHeight, nWidth;
	int* Hist;
	unsigned char** ch_in_gray;

	Mat src = imread("lena_gray.jpg", IMREAD_GRAYSCALE);
	nHeight = src.rows;
	nWidth = src.cols;
	ch_in_gray = MemAlloc2D(nHeight, nWidth);
	Hist = NULL;

	for (int h = 0; h < nHeight;h++)
	{
		for (int w = 0; w < nWidth;w++)
		{
			ch_in_gray[h][w] = src.at<unsigned char>(h, w);
		}
	}
	//imshow("Original_Gray_Image", src);
	//getHistogram(nHeight, nWidth, ch_in_gray, Hist);
	HistogramEqualization(nHeight, nWidth, ch_in_gray, Hist);

	return 0;
}
void HistogramEqualization(int nHeight, int nWidth, unsigned char** ch_in_gray, int* Hist)
{
	if (Hist == NULL)
	{
		Hist = new int[256];// 갯수 체크용
		memset(Hist, 0, sizeof(int) * 256);

		//Get Histogram

		for (int h = 0; h < nHeight;h++)
		{
			for (int w = 0; w < nWidth;w++)
			{
				Hist[ch_in_gray[h][w]]++;
			}
		}
	}

	Mat Eq_Img = Mat(nHeight, nWidth, CV_8UC1);//원본이 equal된 영상
	Mat Eq_Hist_Img = Mat(256, 256, CV_8UC1);//equal된 영상의 hist
	Eq_Hist_Img = Scalar::all(0);

	//Get CDF
	float Hist_CDF[256] = { 0.0 };
	Hist_CDF[0] = (double)Hist[0] / (nHeight * nWidth);
	for (int i = 1;i < 256;i++)
	{
		Hist_CDF[i] = ((double)Hist[i] / (nHeight * nWidth)) + Hist_CDF[i - 1];
	}

	//[0,1]로 정규화된 CDF를 [0,255]로 Scaling


	for (int i = 0; i < 256; i++) {
		Hist_CDF[i] = round(Hist_CDF[i] * 255);
	}
	//Display
	for (int h = 0;h < nHeight;h++)
	{
		for (int w = 0; w < nWidth;w++)
		{
			Eq_Img.at<unsigned char>(h, w) = Hist_CDF[ch_in_gray[h][w]];
		}
	}
	////////////############################################////////////////////////////////////


	//그래프만들기
	for (int h = 0; h < nHeight;h++)
	{
		for (int w = 0; w < nWidth;w++)
		{
			ch_in_gray[h][w] = Eq_Img.at<unsigned char>(h, w);
		}
	}
	Hist = new int[256];
	memset(Hist, 0, sizeof(int) * 256);
	for (int h = 0;h < nHeight;h++)
	{
		for (int w = 0; w < nWidth; w++)
		{
				Hist[ch_in_gray[h][w]]++;
		}
	}
	//Normalize 히스토
	int nMax = 0;
	for (int i = 0;i < 256;i++)
	{
		if (nMax < Hist[i])
		{
			nMax = Hist[i];
		}
	}
	double dNormalizeFactor = 255.0 / nMax;

	for (int w = 0;w < 256;w++)
	{
		int nNormalValue = (int)Hist[w] * dNormalizeFactor;
		for (int h = 255; h > 255 - nNormalValue;h--)
		{
			Eq_Hist_Img.at<unsigned char>(h, w) = 255;
		}
	}
	

	imshow("Histogram Equalization_ Image", Eq_Img);
	imshow("Histgram Equalization_ Histogram", Eq_Hist_Img);
	waitKey(0);

}*/