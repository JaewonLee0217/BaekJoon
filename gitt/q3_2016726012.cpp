/*
3, Color slicing (�� ������ ������� �ٸ� ������ ������ �����̴� �ڵ带 �� �����ϱ� �ٶ�)

��ǥ: �󱼻������κ��� �󱼸� �����ϴ� ���α׷� ����

  - ������ �����̳� ������ �ٸ� ����� ������ ����ص� ��



1) �󱼿����� ���� ������ Ȯ��

   program���� �ۼ��ϰų�, ������ �׸����� �̿��ص� �������

2) ������ pixel ���� �����Ͽ� �󱼻� ���θ� �Ǵ�.

   (1) ��� ������ ������ ���� ������� ����

          - �ش� Pixel�� �󱼻��̸� �� Pixel���� ������� �״�� ����

          - �ش� Pixel�� �󱼻��� �ƴϸ� (0,0,0)�� ������� �״�� ����

   (2) �� map�� ������ Mat�� ����

          - Map�� ũ��� ����ũ��� �����ϳ� 1���� ���� �����ϴ� matrix�� ����

          - �ش� Pixel�� �󱼻��̸� 255�� ����

          - �ش� Pixel�� �󱼻��� �ƴϸ� 0�� ����

          - map�� imshow�� Ȯ���ϸ�, black and white�� �� ������ �� �� ����
*/

#include "stdafx.h"
#include <math.h>
#include <stdlib.h>>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>

/*
using namespace cv;
using namespace std;

int main()
{
    Mat img_in = imread("Test20167260122.jpg"); //�ĺ� ����

    const int T = 40;//���� ����.
    imshow("Test20167260122", img_in);
    unsigned char* pDataRGB = img_in.data;
    // printf("%d %d", pDataRGB[128], pData[129]);
    //�󱼻��� �߽��� �Ǵ� �� ���� or �װ��� rgb���� ���Ѵ�
     //��ճ���(112,95)~(130,112)
    uchar B, G, R;
    int averB = 0;
    int averG = 0;
    int averR = 0;
    int count = 0;
    for (int row = 95; row < 112; row++)
    {
        for (int col = 112; col < 130; col++)
        {

            B = pDataRGB[row * img_in.cols * 3 + col * 3];
            G = pDataRGB[row * img_in.cols * 3 + col * 3 + 1];
            R = pDataRGB[row * img_in.cols * 3 + col * 3 + 2];
            averB += B;
            averG += G;
            averR += R;
            count++;
        }
    }
    averB = averB / count;
    averG = averG / count;
    averR = averR / count;
    ///�󱼻� �߽� ��� ���� ���� �Ϸ�.

    Mat face(img_in.rows, img_in.cols, CV_8UC1);//face map
    //matrix ����
    unsigned char** map;
    map = new unsigned char* [img_in.rows];
    for (int h = 0;h < img_in.rows;h++)
    {
        map[h] = new unsigned char[img_in.cols];
    }
    //
    for (int row = 0; row < img_in.rows; row++)
    {
        for (int col = 0; col < img_in.cols; col++)
        {
            uchar b, g, r;

            b = pDataRGB[row * img_in.cols * 3 + col * 3];
            g = pDataRGB[row * img_in.cols * 3 + col * 3 + 1];
            r = pDataRGB[row * img_in.cols * 3 + col * 3 + 2];
            if (abs(b - averB) < T && abs(g - averG) < T && abs(r - averR) < T)
            {
                //�󱼻� ���־ȿ� ����
                map[row][col] = 255;
            }
            else
            {
                map[row][col] = 0;
            }
            face.at<uchar>(row, col) = map[row][col];

        }
    }
    imshow("face map", face);

    waitKey(0);
    return 0;
}
*/