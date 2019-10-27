#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a[50005];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int b;
		cin>>b;
		a[i]=a[i-1]+b;
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int s,e;
		cin>>s>>e;
		cout<<a[s+e-1]-a[s-1]<<endl;
	}
}
