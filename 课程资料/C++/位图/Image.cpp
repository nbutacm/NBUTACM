
#include "Image.h"


Image::Image()
{
	m_width = 0;
	m_height = 0;
	m_pData = (unsigned char *)null;
}

//ͨ������·������ͼ�����ݣ����ߣ�����
Image::Image(string str)
{
	const char * imgPath = str.c_str();
	fstream rfile;
    rfile.open(imgPath,std::fstream::in|std::fstream::binary);

	//�쳣����
    if(!rfile)
    {
        cerr<<"Open image failed!"<<std::endl;
		return;
    }

	//�����ļ�����
	//rfile.seekg(0,std::ios::end);
	//long length = rfile.tellg();

	//��ָ�������ļ���ͷ
	rfile.seekg(0,std::ios::beg);
	char a;//����bmp�ļ���һ���ַ��Ƿ�Ϊ��B��
	char b;//����bmp�ļ��ڶ����ַ��Ƿ�Ϊ��M��
	rfile.read(&a,1);
	rfile.read(&b,1);
	if('B'!=a || 'M' != b)
	{
		cerr<<"�򿪵�Ϊ��λͼ�ļ�!"<<std::endl;
		return;
	}

	rfile.seekg(18,std::ios::beg);//�ƶ�18λ��λͼ���λ��
	rfile.read((char*)&m_width,sizeof(long));
	rfile.read((char*)&m_height,sizeof(long));

	//��m_pData�����ڴ��
	m_pData = new unsigned char[m_width*m_height];

	rfile.seekg(10,std::ios::beg);//�ƶ�10λ��λͼ�洢λ�õ�ַ
	long move;//λͼ����λ��
	rfile.read((char*)&move,sizeof(long));

	rfile.seekg(move,std::ios::beg);//�ƶ�moveλ��λͼ���ݴ洢λ��
	rfile.read((char*)m_pData,m_width*m_height);

	//a = m_pData[0];//����


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

//��ͺ��ֵ������img1������,ע��˽�г�Ա�ǿ���ֱ�ӷ��ʵ�
Image& operator +(Image & img1, Image & img2)
{
	if(0 == img1.GetWidth() || 0 == img1.GetHeight()||0 == img2.GetWidth()||0 == img2.GetHeight())
	{
		cerr << "�в����ڵ�ͼ������" << endl;
		return img1;
	}
	if(img1.GetWidth()!=img2.GetWidth() || img1.GetHeight() != img2.GetHeight())
	{
		cerr << "����ͼ�����ݿ�߲�һ��" << endl;
		return img1;
	}

	int i = 0;
	for(;i != img1.GetWidth()*img1.GetHeight(); i++)
	{
		img1.m_pData[i] = (img1.m_pData[i]+img2.m_pData[i])%256;
	}

	return img1;
}
