#include <bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int c,m,x;
		cin>>c>>m>>x;
		cout<<min(min(c,m),(c+m+x)/3)<<endl;
	}
}
