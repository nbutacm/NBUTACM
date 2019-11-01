#include<iostream>
#include<cmath>
#include<stdio.h>
#include<set>
#include<map>
#include<string.h>
#include<queue>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
#define _f(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define __f(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
const int MAXN=2e6+100;
typedef long long ll;
using namespace std;
#define PI acos(-1)
int a[MAXN];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(n==0||m==0)cout<<"First"<<endl;
		else if((n+m)%2==0)cout<<"Second"<<endl;
		else cout<<"First"<<endl;
	}
}