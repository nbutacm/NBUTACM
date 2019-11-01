//A - Scarborough Fair    CodeForces - 897A
// 将l-r之间的c1换成c2
//注意 l和r 是以1 开始的，而字符串下标是以0开始的 

#include<iostream>
#include<string>
using namespace std;

int n,m;
string s;
int l,r;
char c1,c2;

int main(){
	cin>>n>>m;
	cin>>s;
	while(m--){
		cin>>l>>r>>c1>>c2;
		for(int i=l;i<=r;i++){
			if(s[i-1]==c1) s[i-1]=c2;
		}
	}
	cout<<s<<endl;
}
