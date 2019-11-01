#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[201];
	int i,num;
	while(~scanf("%s",a))
	{
		num=strlen(a);
		for(i=0;i<num;i++)
		{
			if(a[i]=='0') printf("%c",'1');
			if(a[i]=='1') printf("%c",'0');
		}
		printf("\n");
	}
	return 0;
} 
