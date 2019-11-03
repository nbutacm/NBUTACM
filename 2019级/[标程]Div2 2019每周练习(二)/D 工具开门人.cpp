#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct people
{
	string id, in, out;
};
bool cmp(people a, people b)
{
	return a.in < b.in;
}
bool ccmp(people a, people b)
{
	return a.out > b.out;
}
int main() 
{
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			int n;
			people book[105];
			cin >> n;
			for (int i = 1; i <= n; i++)
			{
				cin >> book[i].id >> book[i].in >> book[i].out;
			}
			sort(book + 1, book + 1 + n, cmp);
			cout << book[1].id << " ";
			sort(book + 1, book + 1 + n, ccmp);
			cout << book[1].id << endl;
		}
	}
	system("pause");
	return 0;
}