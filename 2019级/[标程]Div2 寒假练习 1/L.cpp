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
int main()
{
	int T;
	while (cin >> T)
	{
		int ans = 1, book[1005], m;
		memset(book, MaxDegree, sizeof(book));
		while (T--)
		{
			cin >> m;
			int mi = 0, x = 0;
			for (int i = 1; i <= ans; i++)
			{
				if (m <= book[i] && m > mi)
				{
					x = i;
					mi = m;
				}
			}
			if (x == 0)
			{
				ans++;
				book[ans] = m;
			}
			else
			{
				book[x] = mi;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
