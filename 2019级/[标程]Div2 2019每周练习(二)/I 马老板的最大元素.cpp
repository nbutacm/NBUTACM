#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int m = s[0], len = s.length();
		for (int i = 0; i < len; i++)
		{
			if (s[i] > m)
			{
				m = s[i];
			}
		}
		for (int i = 0; i < len; i++)
		{
			cout << s[i];
			if (m == s[i])
			{
				cout << "(max)";
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}