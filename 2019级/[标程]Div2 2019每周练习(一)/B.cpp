#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	double s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(i%2==1) s++;
	printf("%.10lf\n",s/(n*1.0));
}
