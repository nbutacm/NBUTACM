#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
#include <cmath>
#define FAST_IO ios::sync_with_stdio(false)
#define clr(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 10005;

int main(){
	FAST_IO;
	int T;
	string s;
	cin >> T;
	while(T--){
		cin >> s;
		int st = 0;
		int l = s.length();
		bool flag = 1;
		for(int i=0;i<l;i++){
			if(s[i]=='1'&&st==0){
				flag = 0;
				break;
			} 
			if(s[i]=='1') st--;
			else st++;
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}