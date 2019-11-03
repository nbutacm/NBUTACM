#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int M1 = n, M2 = m, R1 = 0, R2 = 0, R3 = 0;
		string s;
		cin >> s;
		for (int i = 0; i <= s.length(); i++)
		{
			if (s[i] == 'A')
			{
				R1 = M1;
			}
			else if (s[i] == 'B')
			{
				R2 = M2;
			}
			else if (s[i] == 'C')
			{
				M1 = R3;
			}
			else if (s[i] == 'D')
			{
				M2 = R3;
			}
			else if (s[i] == 'E')
			{
				R3 = R1 + R2;
			}
			else
			{
				R3 = R1 - R2;
			}
		}
		cout << M1 << "," << M2 << endl;
	}
	system("pause");
	return 0;
}