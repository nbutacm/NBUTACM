#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	int a[105];
	int dp[10000]={0};
	int sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}                                     //可以看成01背包 
	for(int i=0;i<n;i++){
		for(int j=sum/2;j>=a[i];j--){
			dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
		}
	}
	cout<<abs((sum-dp[sum/2])-dp[sum/2])<<endl;
}
