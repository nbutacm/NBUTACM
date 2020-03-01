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
int sum, n, m, book[105][105], x, y;
string s;
void read(int a, int b)
{
	if (book[a + 1][b] == 1)
	{
		sum++;
		book[a + 1][b] = 0;
		read(a + 1, b);
	}
	if (book[a][b + 1] == 1)
	{
		sum++;
		book[a][b + 1] = 0;
		read(a, b + 1);
	}
	if (book[a - 1][b] == 1)
	{
		sum++;
		book[a - 1][b] = 0;
		read(a - 1, b);
	}
	if (book[a][b - 1] == 1)
	{
		sum++;
		book[a][b - 1] = 0;
		read(a, b - 1);
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
		memset(book, 0, sizeof(book));
		for (int i = 1; i <= m; i++)
		{
			cin >> s;
			for (int j = 0; j <= n - 1; j++)
			{
				if (s[j] == '.')
				{
					book[i][j + 1] = 1;
				}
				else if (s[j] == '@')
				{
					x = i;
					y = j + 1;
				}
			}
		}
		sum = 1;
		read(x, y);
		cout << sum << endl;
	}
	return 0;
}
