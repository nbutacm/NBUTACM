#include<iostream>
#include<string.h>
#include<stdio.h> 
using namespace std;
int main()
{
	
	char a[300];
	int num[250];              // �� C,H,O,N ������  �� num['C'],num['H'],num['O'],num['N']  
	int n;
	scanf("%d",&n);
	getchar();
	for(int j=0;j<n;j++)
	{	
		scanf("%s",a);
		memset(num,0,sizeof(num));
		int len=strlen(a);
		int m=0;
		char flag;
		
		for(int i=0;i<len;i++)
		{
			if(i==0)
			{
				flag=a[i];
				m=1; 
			}
			else{
				if(a[i]>='A'&&a[i]<='Z')//�������ĸ 
				{       
					num[flag]+=m;
					flag=a[i];
					m=1;
				}
				else                     //��������� 
				{                        
					if(a[i-1]>='A'&&a[i-1]<='Z')
					{
						m=0;
					}
					m=m*10+(a[i]-'0'); 
				}
			}
		}
		num[flag]+=m;             //�����һ��Ԫ�ؼ�ֵ
		double ans=12.01*num['C']+1.008*num['H']+16.00*num['O']+14.01*num['N'];
		printf("%.3lf\n",ans); 
	} 
	return 0;
}
