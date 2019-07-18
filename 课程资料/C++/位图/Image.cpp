
#include "Image.h"


Image::Image()
{
	m_width = 0;
	m_height = 0;
	m_pData = (unsigned char *)null;
}

//通过绝对路径输入图像数据，宽，高，数据
Image::Image(string str)
{
	const char * imgPath = str.c_str();
	fstream rfile;
    rfile.open(imgPath,std::fstream::in|std::fstream::binary);

	//异常处理
    if(!rfile)
    {
        cerr<<"Open image failed!"<<std::endl;
		return;
    }

	//测试文件长度
	//rfile.seekg(0,std::ios::end);
	//long length = rfile.tellg();

	//将指针移至文件开头
	rfile.seekg(0,std::ios::beg);
	char a;//测试bmp文件第一个字符是否为‘B’
	char b;//测试bmp文件第二个字符是否为‘M’
	rfile.read(&a,1);
	rfile.read(&b,1);
	if('B'!=a || 'M' != b)
	{
		cerr<<"打开的为非位图文件!"<<std::endl;
		return;
	}

	rfile.seekg(18,std::ios::beg);//移动18位到位图宽度位置
	rfile.read((char*)&m_width,sizeof(long));
	rfile.read((char*)&m_height,sizeof(long));

	//给m_pData分配内存块
	m_pData = new unsigned char[m_width*m_height];

	rfile.seekg(10,std::ios::beg);//移动10位到位图存储位置地址
	long move;//位图数据位置
	rfile.read((char*)&move,sizeof(long));

	rfile.seekg(move,std::ios::beg);//移动move位到位图数据存储位置
	rfile.read((char*)m_pData,m_width*m_height);

	//a = m_pData[0];//测试


}

Image::~Image()
{

	if((unsigned char*)null != m_pData)
	{
		delete []m_pData;
		m_pData = (unsigned char*)null;
	}
}

int Image::SetImage(long width, long height, unsigned char *  pData)
{
	m_width = width;
	m_height = height;
	m_pData = pData;
	return 0;
}

float Image::Average()
{
	int i = 0;
	long sum = 0;
	for(;i != m_width*m_height; i++)
	{
		sum += m_pData[i];
	}
	return (float)(sum*1.0/(m_width*m_height));
}

float Image::Variance()
{
	int i = 0;
	long sum = 0;
	float fAve = 0.0;
	for(;i != m_width*m_height; i++)
	{
		sum += m_pData[i];
	}
	fAve = (float)(sum*1.0/(m_width*m_height));

	double lSum = 0.0;
	for(i=0;i != m_width*m_height; i++)
	{
		lSum += (fAve-m_pData[i])*(fAve-m_pData[i]);
	}

	return (float)(lSum/(m_width*m_height-1));
}

long Image::GetWidth()
{
	return m_width;
}

long Image::GetHeight()
{
	return m_height;
}

//求和后的值保存在img1对象中,注意私有成员是可以直接访问的
Image& operator +(Image & img1, Image & img2)
{
	if(0 == img1.GetWidth() || 0 == img1.GetHeight()||0 == img2.GetWidth()||0 == img2.GetHeight())
	{
		cerr << "有不存在的图像数据" << endl;
		return img1;
	}
	if(img1.GetWidth()!=img2.GetWidth() || img1.GetHeight() != img2.GetHeight())
	{
		cerr << "两张图像数据宽高不一致" << endl;
		return img1;
	}

	int i = 0;
	for(;i != img1.GetWidth()*img1.GetHeight(); i++)
	{
		img1.m_pData[i] = (img1.m_pData[i]+img2.m_pData[i])%256;
	}

	return img1;
}
