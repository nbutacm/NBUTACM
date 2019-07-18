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
        long m_width; //宽度
	    long m_height; //高度
        unsigned char * m_pData;//指向图像数据的指针

    public:
        Image();
        Image(string str);
	    ~Image();
		int SetImage(long width, long height, unsigned char *    pData);
	    float  Average();
        float  Variance();
		long GetWidth();//获取宽度
		long GetHeight();//获取高度

friend Image& operator+(Image & img1, Image & img2);

};

#endif