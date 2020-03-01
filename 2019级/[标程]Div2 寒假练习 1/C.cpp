#include<iostream>
#include<cmath>
using namespace std;
long long b, c, a, q;
int main()
{
	cin >> q;
	while(q--)
	{
		cin >> a >> b >> c;
		if(a == b && b == c)  cout << 0 << endl;
		else if(abs(a - b) + abs (c - b) + abs(a - c) - 4 <= 0)
		{
			cout << 0 << endl;
		}
		else cout << abs(a - b) + abs (c - b) + abs(a - c) - 4 << endl; 
	}
}
