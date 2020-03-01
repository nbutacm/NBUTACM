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

int T, x, y, book[100005];
int main()
{
	
	while (cin >> T)
	{
		memset(book, 0, sizeof(book));
		if (T == 0)
		{
			break;
		}
		for (int i = 1; i <= T; i++)
		{
			scanf("%d%d", &x, &y);
			book[x]++;
			book[y + 1]--;
		}
		int ans = 0;
		for (int i = 1; i <= T; i++)
		{
			ans += book[i];
			if (i != T)
			{
				printf("%d ", ans);
			}
			else
			{
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
