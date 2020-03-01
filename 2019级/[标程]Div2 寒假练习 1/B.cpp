#include<iostream>
#include<cmath>
using namespace std;
long long  a, n;
double r;
const double pai = acos(-1);
int main()
{
	while(cin >> n >> a)
	{
		r = a * sin(pai / n) / (1 - sin(pai / n));
		printf("%f", r);
		cout << endl;
	}
}
