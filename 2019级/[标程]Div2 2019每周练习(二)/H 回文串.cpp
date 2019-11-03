#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	string s;
	int step = 0;
	while (cin >> s)
	{
		if (s == "STOP")
		{
			break;
		}
		step++;
		int len = s.length(), r = 0;
		for (int i = 0; i <= len / 2; i++)
		{
			if (s[i] != s[len - 1 - i])
			{
				cout << "#" << step << ": NO" << endl;
				r = 1;
				break;
			}
		}
		if (r == 0)
		{
			cout << "#" << step << ": YES" << endl;
		}
	}
	system("pause");
	return 0;
}