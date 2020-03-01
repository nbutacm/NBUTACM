#include<iostream>
#include<string.h>
#define M 1009
using namespace std;
struct node
{
	int eg;
	int mon;
}food[M];
long long t, n, m;
long long f[M];
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++) cin >> food[i].eg;
		for(int i = 1; i <= n; i++) cin >> food[i].mon;
		for(int i = 1; i <= n; i++)
		{
			for(int j = m; j >= food[i].mon; j--)
			{
				f[j] = max(f[j],  f[j-food[i].mon] + food[i].eg);
			}
		}
		cout << f[m] << endl;
	}
	return 0;
}
