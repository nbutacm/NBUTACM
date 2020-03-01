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
int book[10005];
void init(int n)
{
	for (int i = 2; i *i <= n; i++)
	{
		if (n%i == 0)
		{
			book[n] = 1;
			return;
		}
	}
}
int main()
{
	memset(book, 0, sizeof(book));
	for (int i = 4; i <= 10000; i++)
	{
		init(i);
	}
	int M;
	while (cin >> M)
	{
		for (int i = M / 2; i >= 2; i--)
		{
			if (book[i] == 0 && book[M - i] == 0)
			{
				cout << i << " " << M - i << endl;
				break;
			}
		}
	}

	return 0;
}
