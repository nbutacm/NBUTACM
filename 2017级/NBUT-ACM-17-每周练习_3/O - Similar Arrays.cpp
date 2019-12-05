#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int data[1000];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int i,j,sum=0,a;
		for(i=0;i<n;i++)
		{
			scanf("%d",&data[i]);
			if(data[i]%2==0)
			{
				sum++;
			}
		}
		a = pow(3,n)-pow(2,sum);
		printf("%d\n",a);
	}
	
	return 0;
}



//  每位数字都有三种选择 比自己小1，和自己相等，比自己大1
//  所以全部方案共有 3^n 种
//  我们再从中挑出所有数均为奇数的排列

//  当原来的数位偶数时 他有2种可能会变成奇数 
//  当原来的数为奇数时 他有1种可能会变成奇数
//  所以 有数均为奇数的排列 有 2^(偶数数量)*1^(奇数数量) =2^(偶数数量)

//  所以 ans=3^(n)-2^(偶数数量) 

