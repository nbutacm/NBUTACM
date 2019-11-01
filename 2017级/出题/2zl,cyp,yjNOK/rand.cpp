#include<bits/stdc++.h>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))

int main()
{ 
	srand(time(0));
	int q;
	cin>>q;
	while(q--)
	{
		int l,n,c,t,vr,vt1,vt2;
		l=rand()%10000;
		n=rand()%100;
		c=rand()%1000;
		t=rand()%100;
		vr=rand();
		vt1=rand();
		vt2=rand();
		cout<<l<<endl;
		cout<<n<<" "<<c<<" "<<t<<endl;
		cout<<vr<<" "<<vt1<<" "<<vt2<<endl;
		int a,b;
		a=random(0,l);
		cout<<a;
		b=a;
		for(int i=1;i<n;i++)
		{
			b=random(b,l);
			cout<<" "<<b;
		}
		cout<<endl;
	}
	return 0;
}
