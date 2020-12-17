#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
/*

//RGBHSV
int main()
{

    Mat src = imread("lena.jpg");

    Mat hsi(src.rows, src.cols, src.type());

    float r, g, b, h, s, in;

    for (int i = 0; i < src.rows; i++)
    {
        for (int j = 0; j < src.cols; j++)
        {
            b = src.at<Vec3b>(i, j)[0];
            g = src.at<Vec3b>(i, j)[1];
            r = src.at<Vec3b>(i, j)[2];

            in = (b + g + r) / 3;

            int min_val = 0;
            min_val = min(r, min(b, g));

            s = 1 - 3 * (min_val / (b + g + r));
            if (s < 0.00001)
            {
                s = 0;
            }
            else if (s > 0.99999) {
                s = 1;
            }

            if (s != 0)
            {
                h = 0.5 * ((r - g) + (r - b)) / sqrt(((r - g) * (r - g)) + ((r - b) * (g - b)));
                h = acos(h);

                if (b <= g)
                {
                    h = h;
                }
                else {
                    h = ((360 * 3.14159265) / 180.0) - h;
                }
            }

            hsi.at<Vec3b>(i, j)[0] = (h * 180) / 3.14159265;
            hsi.at<Vec3b>(i, j)[1] = s * 100;
            hsi.at<Vec3b>(i, j)[2] = in;


        }
    }

    imshow("RGB image", src);
    imshow("HSI image", hsi);

    waitKey(0);
    return 0;
}
//Piecewise-Linear
int computeOutput(int, int, int, int, int);

int main()
{
    Mat image = imread("lena.jpg");
    Mat new_image = image.clone();

    //Piecewise-Linear의 왼쪽아래 점 하고 오른쪽 위 점
    int r1, s1, r2, s2;
    cout << "Enter r1: " << endl; cin >> r1;
    cout << "Enter s1: " << endl; cin >> s1;
    cout << "Enter r2: " << endl; cin >> r2;
    cout << "Enter s2: " << endl; cin >> s2;

    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            for (int c = 0; c < 3; c++) {
                int output = computeOutput(image.at<Vec3b>(y, x)[c], r1, s1, r2, s2);
                new_image.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(output);
            }
        }
    }

    namedWindow("Original Image", 1);
    imshow("Original Image", image);

    namedWindow("New Image", 1);
    imshow("New Image", new_image);

    waitKey();

    return 0;
}

int computeOutput(int x, int r1, int s1, int r2, int s2)
{
    float result;
    if (0 <= x && x <= r1) {
        result = s1 / r1 * x;
    }
    else if (r1 < x && x <= r2) {
        result = ((s2 - s1) / (r2 - r1)) * (x - r1) + s1;
    }
    else if (r2 < x && x <= 255) {
        result = ((255 - s2) / (255 - r2)) * (x - r2) + s2;
    }
    return (int)result;
}


//Canny
 /
Mat extract_colors(Mat Ori)
{
	Mat img_bgr, img_hsv, img_mixed;
	Mat white_mask, white_image, yellow_mask, yellow_image;
	Ori.copyTo(img_bgr);

	//흰색 추출
	inRange(img_bgr, white_min, white_Max, white_mask);
	bitwise_and(img_bgr, img_bgr, white_image, white_mask);

	//노란색 추출
	cvtColor(img_bgr, img_hsv, COLOR_BGR2HSV);

	inRange(img_hsv, yellow_min, yellow_Max, yellow_mask);
	bitwise_and(img_bgr, img_bgr, yellow_image, yellow_mask);

	//두 색의 결과를 합치는 과정
	addWeighted(white_image, 1.0, yellow_image, 1.0, 0.0, img_mixed);

	return img_mixed;
}

Mat Filtering(unsigned char* input, int width, int height, int Fsize = 3)
{
	Mat Padding;
	unsigned char* pData;

	int Psize = Fsize / 2;
	Padding = Mat(height + 2 * Psize, width + 2 * Psize, CV_8UC1);
	pData = Padding.data;
	for (int i = 0; i < Padding.rows; i++)
	{
		for (int j = 0; j < Padding.cols; j++)
		{
			pData[i * Padding.cols + j] = 0;
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pData[(i + Psize) * Padding.cols + (j + Psize)] = input[i * width + j];
		}
	}
	return Padding;
}
Mat Sobel_Vertical(unsigned char* input, int width, int height, int Fsize = 3)
{
	Mat Filtered;
	unsigned char* fData;
	double** Kernel = new double* [Fsize];
	int Psize = int(Fsize / 2);

	for (int i = 0; i < Fsize; i++)
	{
		Kernel[i] = new double[Fsize];
	}

	for (int i = 0; i < Fsize; i++)
	{
		for (int j = 0; j < Fsize; j++)
		{
			Kernel[i][j] = -1;
		}
	}

	for (int i = 0; i < Fsize; i++)
	{
		for (int j = 0; j < Fsize; j++)
		{
			if (j == 1)
			{
				Kernel[i][j] = 0;
			}
			else if (j == 2)
			{
				Kernel[i][j] = -Kernel[i][j];
				if (i == 1)
				{
					Kernel[i][j] *= 2;
				}
			}
			else
			{
				if (i == 1)
				{
					Kernel[i][j] *= 2;
				}
			}
		}
	}
	Filtered = Mat(height, width, CV_8UC1);


	fData = Filtered.data;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			double Y = 0;
			for (int k = 0; k < Fsize; k++)
			{
				for (int l = 0; l < Fsize; l++)
				{
					Y += input[(i + k) * (width + 2 * Psize) + j + l] * Kernel[k][l];
				}
			}

			if (Y > 255)
			{
				fData[i * width + j] = 255;
			}
			else if (Y < 0)
			{
				fData[i * width + j] = 0;
			}
			else
			{
				fData[i * width + j] = Y;
			}
		}
	}


	for (int i = 0; i < Fsize; i++)
	{
		delete[] Kernel[i];
	}

	delete[] Kernel;

	return Filtered;
}
Mat Sobel_Horizontal(unsigned char* input, int width, int height, int Fsize = 3)
{
	Mat Filtered;
	unsigned char* fData;
	double** Kernel = new double* [Fsize];
	int Psize = int(Fsize / 2);

	for (int i = 0; i < Fsize; i++)
	{
		Kernel[i] = new double[Fsize];
	}

	for (int i = 0; i < Fsize; i++)
	{
		for (int j = 0; j < Fsize; j++)
		{
			Kernel[i][j] = -1;
		}
	}

	for (int i = 0; i < Fsize; i++)
	{
		for (int j = 0; j < Fsize; j++)
		{
			if (i == 1)
			{
				Kernel[i][j] = 0;
			}
			else if (i == 2)
			{
				Kernel[i][j] = -Kernel[i][j];
				if (j == 1)
				{
					Kernel[i][j] *= 2;
				}
			}
			else
			{
				if (j == 1)
				{
					Kernel[i][j] *= 2;
				}
			}
		}
	}

	Filtered = Mat(height, width, CV_8UC1);


	fData = Filtered.data;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			double Y = 0;
			for (int k = 0; k < Fsize; k++)
			{
				for (int l = 0; l < Fsize; l++)
				{
					Y += input[(i + k) * (width + 2 * Psize) + j + l] * Kernel[k][l];
				}
			}

			if (Y > 255)
			{
				fData[i * width + j] = 255;
			}
			else if (Y < 0)
			{
				fData[i * width + j] = 0;
			}
			else
			{
				fData[i * width + j] = Y;
			}
		}
	}


	for (int i = 0; i < Fsize; i++)
	{
		delete[] Kernel[i];
	}

	delete[] Kernel;

	return Filtered;
}
Mat NMS(unsigned char* input, int width, int height, int Fsize = 3)
{
	Mat Filtered;
	unsigned char* fData;
	double** Kernel = new double* [Fsize];
	int Psize = int(Fsize / 2);

	for (int i = 0; i < Fsize; i++)
	{
		Kernel[i] = new double[Fsize];
	}

	Filtered = Mat(height, width, CV_8UC1);


	fData = Filtered.data;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			double max;
			for (int k = 0; k < Fsize; k++)
			{
				for (int l = 0; l < Fsize; l++)
				{
					Kernel[k][l] = input[(i + k) * (width + 2 * Psize) + j + l];
				}
			}

			max = Kernel[0][0];

			for (int k = 0; k < Fsize; k++)
			{
				for (int l = 0; l < Fsize; l++)
				{
					if (Kernel[k][l] > max)
					{
						max = Kernel[k][l];
					}
				}
			}

			if (max == Kernel[Psize][Psize])
			{
				fData[i * width + j] = input[(i + Psize) * (width + 2 * Psize) + j + Psize];
			}
			else
			{
				fData[i * width + j] = 0;
			}
		}
	}


	for (int i = 0; i < Fsize; i++)
	{
		delete[] Kernel[i];
	}

	delete[] Kernel;

	return Filtered;
}
Mat DT(unsigned char* input, int width, int height, int Fsize = 3)
{
	Mat Filtered;
	unsigned char* fData;
	int Psize = int(Fsize / 2);

	Filtered = Mat(height, width, CV_8UC1);


	fData = Filtered.data;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (input[(i + Psize) * (width + 2 * Psize) + j + Psize] > 150)
			{
				fData[i * width + j] = 255;
			}
			else if (input[(i + Psize) * (width + 2 * Psize) + j + Psize] > 50)
			{
				fData[i * width + j] = 50;
			}
			else
			{
				fData[i * width + j] = 0;
			}

		}
	}

	return Filtered;
}
Mat hysteresis(unsigned char* input, int width, int height, int Fsize = 3)
{
	Mat Filtered;
	unsigned char* fData;
	double** Kernel = new double* [Fsize];
	int Psize = int(Fsize / 2);

	bool check = false;
	for (int i = 0; i < Fsize; i++)
	{
		Kernel[i] = new double[Fsize];
	}

	Filtered = Mat(height, width, CV_8UC1);


	fData = Filtered.data;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (input[(i + Psize) * (width + 2 * Psize) + j + Psize] == 255)
			{
				fData[i * width + j] = 255;
			}
			else if (input[(i + Psize) * (width + 2 * Psize) + j + Psize] == 0)
			{
				fData[i * width + j] = 0;
			}
			else
			{
				for (int k = 0; k < Fsize; k++)
				{
					for (int l = 0; l < Fsize; l++)
					{
						Kernel[k][l] = input[(i + k) * (width + 2 * Psize) + j + l];
					}
				}

				for (int k = 0; k < Fsize; k++)
				{
					for (int l = 0; l < Fsize; l++)
					{
						if (Kernel[k][l] == 255)
						{
							fData[i * width + j] = 255;
							check = true;
							break;
						}

					}
					if (check)
					{
						check = false;
						break;
					}
					else
					{
						fData[i * width + j] = 0;
						break;
					}
				}
			}

		}
	}
	for (int i = 0; i < Fsize; i++)
	{
		delete[] Kernel[i];
	}

	delete[] Kernel;

	return Filtered;

}

void GaussianFilter(Mat In, Mat Out, int nWidth, int nHeight, double sigma)
{
	double gaussian[3][3] = { 0.0 };
	double sum = 0.0;

	for (int h = 0; h < 3; h++)
	{
		for (int w = 0; w < 3; w++)
		{
			double num = -(double)(h * h + w * w) / ((2 * sigma * sigma));
			double e = exp(num);
			double den = 2 * PI * sigma * sigma;
			gaussian[h][w] = (1.0 / den) * e;
			sum += gaussian[h][w];
		}
	}

	for (int h = 0; h < nHeight; h++)
	{
		for (int w = 0; w < nWidth; w++)
		{
			double result = 0;
			int i = 0;
			for (int th = h; th < 3 + h; th++)
			{
				int j = 0;
				for (int tw = w; tw < 3 + w; tw++)
				{
					result += In.at<uchar>(th, tw) * (gaussian[i][j++] / sum);
				}
				i++;
			}
			if (result > 255)
				result = 255;
			else if (result < 0)
				result = 0;

			Out.at<uchar>(h, w) = (unsigned char)result;
		}
	}
}

void Apply_Cannyf(Mat img_filtered, Mat& img_edges) {

	//-1. BGR2GRAY
	Mat img_gray = Mat(img_filtered.rows, img_filtered.cols, CV_8UC1);
	//cvtColor(img_filtered, img_edges, COLOR_BGR2GRAY);

	for (int i = 0; i < img_filtered.rows; i++)
	{
		for (int j = 0; j < img_filtered.cols; j++)
		{
			img_gray.at<uchar>(i, j) = img_filtered.at<Vec3b>(i, j)[0] * 0.114 + img_filtered.at<Vec3b>(i, j)[1] * 0.587 + img_filtered.at<Vec3b>(i, j)[2] * 0.299;
		}
	}
	//imshow("GRAY", img_gray);

		//-2.Padding
	Mat img_pad;
	img_pad = Filtering(img_gray.data, img_gray.cols, img_gray.rows);
	//imshow("padding", img_pad);

		//-3.GaussianFilter

	Mat img_blur = Mat::zeros(img_pad.rows, img_pad.cols, 0);
	GaussianFilter(img_blur, img_blur, img_gray.cols, img_gray.rows, 0);

	//GaussianBlur(img_pad, img_blur, Size(3, 3), 0, 0);
	//imshow("Gaussian Blur", img_blur);

		//-4.Sobel
	Mat img_sobelv;

	img_sobelv = Sobel_Vertical(img_pad.data, img_gray.cols, img_gray.rows);
	//imshow("sobel_vertical", img_sobelv);

	Mat img_sobelh;

	img_sobelh = Sobel_Horizontal(img_pad.data, img_gray.cols, img_gray.rows);
	//imshow("sobel_horizontal", img_sobelh);

	Mat img_sobel;

	bitwise_or(img_sobelh, img_sobelv, img_sobel);

	//imshow("sobel", img_sobel);

	//writer << img_sobel;

	Mat img_sobelp;

	img_sobelp = Filtering(img_sobel.data, img_gray.cols, img_gray.rows);

	//-5.Non-Maximum Suppression

	Mat img_nms;

	img_nms = NMS(img_sobelp.data, img_gray.cols, img_gray.rows);

	//writer << img_nms;
	//imshow("Non Maxium Suppression", img_nms);

		//-6.Double Thresholding
	Mat img_nmsp;

	img_nmsp = Filtering(img_nms.data, img_gray.cols, img_gray.rows);

	Mat img_dt;
	img_dt = DT(img_nmsp.data, img_gray.cols, img_gray.rows);
	//imshow("Double Threshold", img_dt);
	//writer << img_dt;

		//-7.Edge Detecting
	Mat img_dtp;

	img_dtp = Filtering(img_dt.data, img_gray.cols, img_gray.rows);
	Mat img_edge;
	img_edge = hysteresis(img_dtp.data, img_gray.cols, img_gray.rows);
	img_edge.copyTo(img_edges);

}

*/