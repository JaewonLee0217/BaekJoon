#include "stdafx.h"
#include <math.h>

#include <opencv/cv.h>
#include <opencv2/opencv.hpp>

/*1. RGB 영상 포멧 확인


카메라로 촬영한 영상을 opencv의 imread를 이용하여 읽고,

HW#1의 예제를 참고하여 직접 메모리에 접근하여 RGB data가 어떤 식으로

저장되어 있는지 확인하고 보고서에 간략히 설명
*/
/*
using namespace cv;
using namespace std;

int main()
{
	Mat img_in = imread("Camera_2016726012.jpg");

	unsigned char* pData = img_in.data;
	

	for (int row = 0; row < img_in.rows; row++)
	{
		for (int col = 0; col < img_in.cols; col++)
		{
			uchar b = pData[row * img_in.cols * 3 + col * 3];
			uchar g = pData[row * img_in.cols * 3 + col * 3 + 1];
			uchar r = pData[row * img_in.cols * 3 + col * 3 + 2];

		printf(" (%d, %d, %d)", r, g, b);
		
		}
		if (row == 1)
			break;
	}


	waitKey(0);

	return 0;
}
*/