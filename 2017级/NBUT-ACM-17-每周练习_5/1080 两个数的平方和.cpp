#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int a[50005];

int main(){
	cin>>n;
	bool flag=false;
	for(int i=0;;i++){
		if((i*i)>(n-i*i)) break;
		else{
			int m=(int)sqrt(1.0*(n-i*i));
			if(m*m==(n-i*i)){
				flag=true;
				cout<<i<<" "<<m<<endl;
			}
		}
	}
	if(!flag) cout<<"No Solution"<<endl;
}
