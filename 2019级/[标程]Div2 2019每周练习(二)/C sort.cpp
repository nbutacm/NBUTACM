#include<iostream>
#include<algorithm>
using namespace std;
int n, m, book[1000005];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &book[i]);
	}
	sort(book + 1, book + 1 + n, cmp);
	for (int i = 1; i <= m; i++)
	{
		printf("%d", book[i]);
		if (i != m)
		{
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}