#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
#include<stdio.h>
#include<stack>
#include<cstring>
#include<fstream>
using namespace std;
typedef long long ll;
const int Mod = 1e9 + 7;
const int Max = 2000000000;
const int all = 500005;
const double PI = acos(-1);
priority_queue<ll, vector<ll>, greater<ll> >ready;
void right()
{
	for (int i = 0; i <= 30; i++)
	{
		ll a = pow(2, i);
		if (a > Max)
		{
			break;
		}
		for (int j = 0; j <= 30; j++)
		{
			ll b = pow(3, j);
			if (a*b > Max)
			{
				break;
			}
			for (int k = 0; k <= 30; k++)
			{
				ll c = pow(5, k);
				if (a*b*c > Max)
				{
					break;
				}
				for (int l = 0; l <= 30; l++)
				{
					ll d = pow(7, l);
					if (a*b*c*d > Max)
					{
						break;
					}
					else
					{
						ready.push(a*b*c*d);
					}
				}
			}
		}
	}
	return;
}
int main()
{
	right();
	int book[6005];
	for (int i = 1; i <= 5842; i++)
	{
		book[i] = ready.top();
		ready.pop();
	}
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		if (n % 100 == 11 || n % 100 == 12 || n % 100 == 13)
		{
			cout << "The " << n << "th humble number is " << book[n] << "." << endl;
			continue;
		}
		cout << "The " << n;
		if (n % 10 == 1)
		{
			cout << "st humble number is ";
		}
		else if (n % 10 == 2)
		{
			cout << "nd humble number is ";
		}
		else if (n % 10 == 3)
		{
			cout << "rd humble number is ";
		}
		else
		{
			cout << "th humble number is ";
		}
		cout << book[n] << "." << endl;
	}
	return 0;
}
