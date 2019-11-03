#include<iostream>
#include<algorithm>
using namespace std;

int n,k;
int ans;

int binary_search(int l,int r,int k){
	int sum=0;
	while(l<=r){
		sum++;
		int mid=(l+r)/2;
		if(mid==k) return sum;
		if(mid<k) l=mid+1;
		if(mid>k) r=mid-1;
	}
}

int main(){
	while(cin>>n>>k){
		ans=binary_search(1,n,k);
		cout<<ans<<endl;
	}
} 
