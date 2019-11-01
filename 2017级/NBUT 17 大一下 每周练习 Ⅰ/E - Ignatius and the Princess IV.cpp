#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;

/*

找到n个数中的中位数
题目保证中位数出现的次数大于（n／2）次

所以我们可以将数组排序
保证中位数在数组的最中间

*/

LL a[1000005];
int main()
{
	ios::sync_with_stdio(false);
	LL n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		cout<<a[(n+1)/2]<<endl;
	}
	
}