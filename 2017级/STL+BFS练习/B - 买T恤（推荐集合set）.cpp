#include <iostream>
#include <set>
using namespace std;

const int N=200010;
int p[N];

int main(){
	int m,n,x,y;
	set<int> s[4];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i];
	
	for(int i=1;i<=n;i++){
		cin>>x;
		s[x].insert(p[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		s[x].insert(p[i]);
	}
	
	cin>>m;
	while(m--){
		cin>>x;
		if(s[x].empty()){
			cout<<-1<<" ";
		}	
		else{
			cout<<*s[x].begin()<<" ";
			y=*s[x].begin();
			s[1].erase(y);
			s[2].erase(y);
			s[3].erase(y);
		}
	}
	return 0;
}
