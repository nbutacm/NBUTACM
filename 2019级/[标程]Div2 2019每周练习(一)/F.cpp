#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while(getline(cin,s))
	{
		for(int i=0;i<s.size();i++)
		{
			if(i==0 && s[i]!=' ')
				s[i]=s[i]-32;
			if(s[i]==' ')
				s[i+1]=s[i+1]-32;
		}
		cout<<s<<endl;
	}
}
