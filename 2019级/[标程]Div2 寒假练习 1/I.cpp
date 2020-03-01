#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
#include<stdio.h>
#include<stack>
#include<cstring>
#include<fstream>
using namespace std;
int read(string n)
{
	int ans = 0;
	for (int i = 0; i <= n.length() - 1; i++)
	{
		ans = ans * 10 + (n[i] - '0');
	}
	return ans;
}
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a%b);
	}
}
int main()
{
	int T;
	while (cin >> T)
	{
		string s, ss, sss;
		while (T--)
		{
			cin >> s;
			int len = s.length(), r = 0, l = len - 1, type = 1;
			for (int i = 2; i <= len - 1; i++)
			{
				if (s[i] == '(')
				{
					l = i;
				}
				else if (s[i] == ')')
				{
					r = i;
				}
			}
			if (l == len - 1)
			{
				ss = s.substr(2, l);
				int a = read(ss), b = 1, x;
				for (int j = 1; j <= ss.length(); j++)
				{
					b *= 10;
				}
				x = gcd(a, b);
				cout << a / x << "/" << b / x << endl;
			}
			else
			{
				int a = 0, b = 0, x;
				ss = s.substr(2, l - 2);
				sss = s.substr(l + 1, r - l - 1);
				a = read(sss);
				for (int j = 1; j <= sss.length(); j++)
				{
					b = b * 10 + 9;
				}
				x = gcd(a, b);
				if (l - 2 == 0)
				{
					cout << a / x << "/" << b / x << endl;
				}
				else
				{
					a = (a / x) + read(ss)*(b / x);
					b = b / x;
					for (int j = 1; j <= ss.length(); j++)
					{
						b *= 10;
					}
					x = gcd(a, b);
					cout << a / x << "/" << b / x << endl;
				}

			}
		}
	}
	return 0;
}
