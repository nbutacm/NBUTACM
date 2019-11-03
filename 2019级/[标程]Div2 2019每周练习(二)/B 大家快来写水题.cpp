#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
struct node
{
	int value, absvalue;
};
bool cmp(node a, node b)
{
	return a.absvalue > b.absvalue;
}
int main()
{
	int n;
	node book[105];
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> book[i].value;
			book[i].absvalue = abs(book[i].value);
		}
		sort(book + 1, book + 1 + n, cmp);
		for (int i = 1; i <= n; i++)
		{
			cout << book[i].value;
			if (i != n)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
} 