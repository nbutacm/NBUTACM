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
typedef long long ll;
const int Mod = 1e9 + 7;
const int Max = 2000000000;
const int all = 500005;
const double PI = acos(-1);
int main()
{
	int len, n;
	while (cin >> len >> n)
	{
		int book[205];
		char x;
		string s;
		memset(book, 0, sizeof(book));
		cin >> s;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			book[x] = 1;
		}
		ll sum = 0, l = 0;
		for (int i = 0; i <= len - 1; i++)
		{
			if (book[s[i]] == 1)
			{
				l++;
			}
			else
			{
				sum += l * (l + 1) / 2;
				l = 0;
			}
		}
		if (l)
		{
			sum += l * (l + 1) / 2;
		}
		cout << sum << endl;
	}
	return 0;
}
