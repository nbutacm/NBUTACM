#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

string s;
int a[26];
int main(){
	cin>>s;
	memset(a,0,sizeof(a));
	for(int i=0;i<s.size();i++){
		s[i]=tolower(s[i]);
		a[s[i]-'a']++;
	}
	sort(a,a+26);
	int ans=0;
	for(int i=0;i<26;i++){
		ans+=a[i]*(i+1);
	}
	cout<<ans<<endl;
} 
