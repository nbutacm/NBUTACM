#include<iostream>
#include<stdio.h>
using namespace std;
const int MAXN=1e5+5;

int n,m;
int a[MAXN];

int binary_search(int l,int r,int k){
	while(l<=r){
		int mid=(l+r)/2;
		//cout<<l<<" "<<r<<endl;
		//cout<<a[mid]<<endl;
		if(a[mid]==k) return mid;
		if(a[mid]<k) l=mid+1;
		if(a[mid]>k) r=mid-1;
	}
	return -1;
}

int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		while(m--){
			int b;
			scanf("%d",&b);
			printf("%d\n",binary_search(1,n,b));
		}
	}
}
