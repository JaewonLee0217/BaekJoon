#include "stdafx.h"
#include <math.h>

#include <opencv/cv.h>
#include <opencv2/opencv.hpp>

/*1. RGB ���� ���� Ȯ��


ī�޶�� �Կ��� ������ opencv�� imread�� �̿��Ͽ� �а�,

HW#1�� ������ �����Ͽ� ���� �޸𸮿� �����Ͽ� RGB data�� � ������

����Ǿ� �ִ��� Ȯ���ϰ� ������ ������ ����
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