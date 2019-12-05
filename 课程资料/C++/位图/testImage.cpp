#include "Image.h"
#include "windows.h"

int main()
{
	char buf[1000];
	GetCurrentDirectory(1000,buf);//用来查当前路径，可以将图片放在该路径下
	//Image img1("D:\\data\\test1.bmp");//也可以修改为绝对路径
	//Image img2("D:\\data\\test2.bmp");
	Image img1("test1.bmp");
	Image img2("test2.bmp");
	
	cout << "img1的均值" <<img1.Average() << endl;
	cout << "img1的方差" <<img1.Variance() << endl;
	cout << "img2的均值" <<img2.Average() << endl;
	cout << "img2的方差" <<img2.Variance() << endl;

	img1 = img1 + img2;

	return 0;
}