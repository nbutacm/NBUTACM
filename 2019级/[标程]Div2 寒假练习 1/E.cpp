#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n, f;
string s[105];
bool cmp(string s1, string s2)
{
	return s1.length() < s2.length();
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	sort(s + 1, s + 1 + n, cmp);
	for(int i = 2; i <= n; i++)
	{
		if(s[i].find(s[i - 1]) >= s[i].length())
		{
			f = 1;
			break;
		}
	}
	if(!f)
	{
		cout << "YES" << endl;
		for(int i = 1; i <= n; i++)  cout << s[i] << endl;	
	}
	else cout << "NO" << endl;
    return 0;
}
