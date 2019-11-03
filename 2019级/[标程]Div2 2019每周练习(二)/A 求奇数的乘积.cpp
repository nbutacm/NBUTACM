#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 1, x;
		while (n--)
		{
			cin >> x;
			if (x % 2 == 1)
			{
				sum *= x;
			}
		}
		cout << sum << endl;
	}
	return 0;
}