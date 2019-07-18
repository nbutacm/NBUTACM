#ifndef __Image
#define __Image

#ifndef null
#define null ((void *)0)
#endif

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Image
{
    private:
        long m_width; //���
	    long m_height; //�߶�
        unsigned char * m_pData;//ָ��ͼ�����ݵ�ָ��

    public:
        Image();
        Image(string str);
	    ~Image();
		int SetImage(long width, long height, unsigned char *    pData);
	    float  Average();
        float  Variance();
		long GetWidth();//��ȡ���
		long GetHeight();//��ȡ�߶�

friend Image& operator+(Image & img1, Image & img2);

};

#endif