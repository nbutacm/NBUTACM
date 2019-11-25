#include<iostream>
#include<map>
using namespace std;
map<string , int>mp;

int main() {
	int t;
	cin >> t;
	string s;
	while(t--) {
		string s;
		cin >> s;
		mp[s]++;
		if(mp[s] == 1 ) {
			cout << "OK" << endl;
		}
		else {
			cout << s << mp[s]-1 << endl;
		}
		
	}
	return 0;
} 
