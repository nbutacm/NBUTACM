#include<iostream>
using namespace std;
long long n, m, a;
int main()
{
	while(cin >> n >> m >> a)
	{
		ll x = n / a + (n % a == 0 ? 0 : 1);
    	ll y = m / a + (m % a == 0 ? 0 : 1);
		cout << x * y << endl; 
	}
	return 0;
}
