#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int i,num;
	char a[101];
	while(gets(a))
	{
		
		a[0]=a[0]-32;
		for(i=1;i<strlen(a);i++)
		{
			if(a[i]==' ')
			a[i+1]=a[i+1]-32;
		 } 
		printf("%s\n",a);
	}
	return 0;
}

// 使用gets()函数可以无视空格直接读一行 
