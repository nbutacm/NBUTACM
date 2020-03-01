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
string s[105];
int direct[10][2] = { {0, 0}, {1, 0},{0, 1},{-1, 0},{0, -1},{1, 1},{1, -1},{-1, 1},{-1, -1} }, n, m;
void read(int x, int y)
{
	s[x][y] = '*';
	for (int i = 1; i <= 8; i++)
	{
		int a = x + direct[i][0], b = y + direct[i][1];
		if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1)
		{
			if (s[a][b] == '@')
			{
				read(a, b);
			}
		}
	}
}
int main()
{
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		int step = 0;
		for (int i = 0; i <= n - 1; i++)
		{
			cin >> s[i];
		}
		for (int i = 0; i <= n - 1; i++)
		{
			for (int j = 0; j <= m - 1; j++)
			{
				if (s[i][j] == '@')
				{
					step++;
					read(i, j);
				}
			}
		}
		cout << step << endl;
	}
	return 0;
}
