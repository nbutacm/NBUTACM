#include <iostream>
#include <algorithm>

using namespace std;

int cmp (int & a, int & b)
{
	return a > b;	
}

int main(void)
{
	long long n, m, T, i;
	int ans = 0;
	
	cin >> T;
	
	while (T--)
	{
		ans = 0;
		cin >> n >> m;
		while (m > n && n > 0)
		{
			m -= n;
			n--;
			ans++;	
		}
		if (m > 0 && n > 0)
			cout << ans + 1 << endl;
		else
			cout << "-1" << endl;
	}

	return 0;
}
