#include<iostream>
using namespace std;

int main(){
	//freopen("/Users/cccccccccchy/compare/龙王的围棋.in","r",stdin);  
    //freopen("/Users/cccccccccchy/compare/龙王的围棋.out","w",stdout);
	int t,n,m,ans;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		if(n==1&&m==1) ans=0;
		else if(n==1) ans=m-2;
		else if(m==1) ans=n-2;
		else{
			ans=(n-2)*(m-2);
		}
		if(ans%2==1) cout<<"そら ぎんこ"<<endl;
		else cout<<"ひなつる あい"<<endl;
	}
	return 0;
}