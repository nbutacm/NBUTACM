#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[1005];

int binary_search(int l,int r,int k){
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==k) return mid;
		if(a[mid]>k) r=mid-1;
		if(a[mid]<k) l=mid+1;
	}
	return -1;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	
	bool flag=false;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int k=binary_search(j+1,n,0-a[i]-a[j]);
			if(k!=-1){
				flag=true;
				cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
			}
		}
	}
	if(!flag) cout<<"No Solution"<<endl;
	
	return 0; 
}
