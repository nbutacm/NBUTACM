#include "Image.h"
#include "windows.h"

int main()
{
	char buf[1000];
	GetCurrentDirectory(1000,buf);//�����鵱ǰ·�������Խ�ͼƬ���ڸ�·����
	//Image img1("D:\\data\\test1.bmp");//Ҳ�����޸�Ϊ����·��
	//Image img2("D:\\data\\test2.bmp");
	Image img1("test1.bmp");
	Image img2("test2.bmp");
	
	cout << "img1�ľ�ֵ" <<img1.Average() << endl;
	cout << "img1�ķ���" <<img1.Variance() << endl;
	cout << "img2�ľ�ֵ" <<img2.Average() << endl;
	cout << "img2�ķ���" <<img2.Variance() << endl;

	img1 = img1 + img2;

	return 0;
}