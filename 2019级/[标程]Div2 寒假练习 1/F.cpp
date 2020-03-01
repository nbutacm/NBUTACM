#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long  a, n, w;
long long qwq;
double r;
int main()
{
	cin >> n;
	while(n--)
	{
		cin >> w;
		long long ans = 0;
		qwq = 0x3f3f3f3f;
		for(int i = 1; i <= sqrt(w); i++)
		{
			for(int j = 1; j <= sqrt(w); j++)
			{
				long long qaq = w / (i * j);
				if(w % (i * j) == 0)
				{
					qwq = min(qwq,(i * j + i * qaq + j * qaq) * 2);
				}
			}
		}
		cout << qwq << endl;
	}
}
