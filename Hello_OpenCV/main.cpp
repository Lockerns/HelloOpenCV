#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//��ȡ���ص�һ��ͼƬ����ʾ����
	//imread ������ļ�·�����Ը����Լ���ʵ��·���޸ġ�
	Mat img = imread("C:/Users/wzcon/Desktop/remu.jpg");
	imshow("test", img);
	//�ȴ��û�����
	waitKey(0);
	return 0;
}