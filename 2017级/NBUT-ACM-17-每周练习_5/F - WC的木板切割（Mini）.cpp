#include<stdio.h>
#include <algorithm>
using namespace std;
long long a[100000];
int main()
{
	long long  n,i,b;
	long long ans;
	while(~scanf("%I64d",&n))
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%I64d",&a[i]);
		}
		while(n>1)
		{
			int l1=0,l2=1;                                   //l1Ϊ��С��l2Ϊ��С 
			if(a[l1]>a[l2]) swap(a[l1],a[l2]);               //swap ��<algorithm>���Դ��Ľ������� 
			for(i=2;i<n;i++)                       //ÿ����ľ��������С�ʹ�С                       
			{
				if(a[i]<a[l1])
				{
					l2=l1;
					l1=i;
				}
				else if(a[i]<a[l2])
				{
					l2=i;
				}
			}
			b=a[l1]+a[l2];            //bΪ��С����С��ľ����ϳɵ��µ�ľ�� 
			ans+=b;             
			a[l1]=b;                  //��bľ������ԭ����Сľ����λ�� 
			a[l2]=a[n-1];             //�����һ��ľ������ԭ����Сľ����λ�� 
			n--;                      //����ľ��������-1 
		}
		printf("%I64d\n",ans);        
	}
	return 0;
}




