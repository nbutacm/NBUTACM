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
			int l1=0,l2=1;                                   //l1为最小，l2为次小 
			if(a[l1]>a[l2]) swap(a[l1],a[l2]);               //swap 是<algorithm>里自带的交换函数 
			for(i=2;i<n;i++)                       //每次在木棍中找最小和次小                       
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
			b=a[l1]+a[l2];            //b为次小和最小的木棍组合成的新的木棍 
			ans+=b;             
			a[l1]=b;                  //将b木棍放在原来最小木棍的位置 
			a[l2]=a[n-1];             //将最后一根木棍放在原来次小木棍的位置 
			n--;                      //所有木棍的数量-1 
		}
		printf("%I64d\n",ans);        
	}
	return 0;
}




