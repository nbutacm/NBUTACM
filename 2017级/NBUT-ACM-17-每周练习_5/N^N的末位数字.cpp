#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n,k;
ll a[50005]; 

int binary_search(ll l,ll r,ll k){
	while(l<=r){
		ll mid=(l+r)/2;
		if(a[mid]==k) return mid;
		if(a[mid]>k) r=mid-1;
		if(a[mid]<k) l=mid+1;
	}
	return -1;
}

int main(){
	cin>>k>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	bool flag=false;
	for(int i=0;i<n-1;i++){
		int pos=binary_search(i+1,n-1,k-a[i]);
		if(pos!=-1){
			flag=true;
			cout<<a[i]<<" "<<a[pos]<<endl;
		}
	}
	if(flag==false) cout<<"No Solution"<<endl;
} 
