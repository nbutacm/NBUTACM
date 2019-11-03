#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct ballon
{
	int content;
	string coluor;
};
bool cmp(ballon a, ballon b)
{
	return a.content > b.content;
}
int main() 
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		ballon book[105];
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> book[i].coluor >> book[i].content;
		}
		sort(book + 1, book + 1 + n, cmp);
		for (int i = 1; i <= n; i++)
		{
			cout << book[i].coluor;
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