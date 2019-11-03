#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct competition
{
	int begin, end;
};
bool cmp(competition a, competition b)
{
	return a.end < b.end;
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		competition book[105];
		for (int i = 1; i <= n; i++)
		{
			cin >> book[i].begin >> book[i].end;
		}
		sort(book + 1, book + 1 + n, cmp);
		int time = 0, sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (book[i].begin >= time)
			{
				sum++;
				time = book[i].end;
			}
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}