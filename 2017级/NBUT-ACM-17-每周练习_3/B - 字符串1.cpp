#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
	char a[3],tmp;
	while(~scanf("%s",&a))
	{
		sort(a,a+3);
		printf("%c %c %c\n",a[0],a[1],a[2]);
	}
	return 0;
} 


//sort����Ҳ���Ը��ַ���������
//Ĭ��Ϊ��С���� 
