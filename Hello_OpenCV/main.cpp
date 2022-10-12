#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;
static void on_ContrastAndBright(int, void*);
// static void showHelpText;

int g_ContrastValue = 0;
int g_nBrightValue = 0;
Mat g_srcImg, g_dstImg;
int main()
{
	g_srcImg = imread("C:/Users/wzcon/Desktop/z.png");
	if (!g_srcImg.data)
	{
		cout << "ͼƬ·������" << endl;
		return 0;
	}
	g_dstImg = Mat::zeros(g_srcImg.size(), g_srcImg.type());
	g_ContrastValue = 80;
	g_nBrightValue = 80;
	namedWindow("Ч��ͼ����", 1);
	createTrackbar("�Աȶȣ�", "Ч��ͼ����", &g_ContrastValue, 300, on_ContrastAndBright);
	createTrackbar("�� ��", "Ч��ͼ����", &g_nBrightValue, 200, on_ContrastAndBright);

	on_ContrastAndBright(g_ContrastValue, 0);
	on_ContrastAndBright(g_nBrightValue, 0);

	while (char(waitKey(1)) != 'q')
	{
	}
	return 0;
}

static void on_ContrastAndBright(int, void*)
{
	namedWindow("ԭʼͼ����", 1);
	for (int y = 0; y < g_srcImg.rows; y++)
	{
		for (int x = 0; x < g_srcImg.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				g_dstImg.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_ContrastValue * 0.01) *
					(g_srcImg.at<Vec3b>(y, x)[c]) +
					g_nBrightValue);
			}
		}
	}
	imshow("ԭʼͼ����", g_srcImg);
	imshow("Ч��ͼ����", g_dstImg);
}