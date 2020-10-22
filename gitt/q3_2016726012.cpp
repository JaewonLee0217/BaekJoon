/*
3, Color slicing (이 과제의 결과물을 다른 숙제에 응용할 예정이니 코드를 잘 관리하기 바람)

목표: 얼굴사진으로부터 얼굴만 추출하는 프로그램 구현

  - 본인의 사진이나 웹에서 다른 사람의 사진을 사용해도 됨



1) 얼굴영역에 대한 색정보 확인

   program으로 작성하거나, 윈도우 그림판을 이용해도 상관없음

2) 영상의 pixel 값을 접근하여 얼굴색 여부를 판단.

   (1) 결과 영상을 다음과 같은 방법으로 생성

          - 해당 Pixel이 얼굴색이면 그 Pixel값을 결과영상에 그대로 저장

          - 해당 Pixel이 얼굴색이 아니면 (0,0,0)을 결과영상에 그대로 저장

   (2) 얼굴 map을 저장할 Mat를 생성

          - Map의 크기는 영상크기와 동일하나 1개의 값만 저장하는 matrix를 생성

          - 해당 Pixel이 얼굴색이면 255를 저장

          - 해당 Pixel이 얼굴색이 아니면 0을 저장

          - map을 imshow로 확인하면, black and white로 얼굴 영역을 볼 수 있음
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
    Mat img_in = imread("Test20167260122.jpg"); //후보 영상

    const int T = 40;//범주 설정.
    imshow("Test20167260122", img_in);
    unsigned char* pDataRGB = img_in.data;
    // printf("%d %d", pDataRGB[128], pData[129]);
    //얼굴색의 중심이 되는 점 설정 or 그것의 rgb값을 구한다
     //평균내기(112,95)~(130,112)
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
    ///얼굴색 중심 평균 색깔 설정 완료.

    Mat face(img_in.rows, img_in.cols, CV_8UC1);//face map
    //matrix 생성
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
                //얼굴색 범주안에 들어가면
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