#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const ll MAXN=100000+5;

ll n;

struct node{
	ll a,b;
}a[MAXN];

ll cmp(node a,node b){
	return a.b>b.b;
}

int main(){
	scanf("%lld",&n);
	ll sum=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i].a);
		sum+=a[i].a;
	}
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i].b);
	}
	sort(a,a+n,cmp);
	
	if(sum>(a[0].b+a[1].b)) printf("NO\n");
	else printf("YES\n");
}


// 拿结构体练练手 
