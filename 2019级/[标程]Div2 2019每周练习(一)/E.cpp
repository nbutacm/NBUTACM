#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int f=0;
		for(int i=2;i*i<=n;i++)
			if(n%i==0) f=1;
		if(f==1) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}
