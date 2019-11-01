#include<iostream>
using namespace std;

int main(){
	//freopen("/Users/cccccccccchy/compare/WC有趣的暑假时光.in","r",stdin);  
    //freopen("/Users/cccccccccchy/compare/WC有趣的暑假时光.out","w",stdout);
	int t,n,a,b,c,ans;
	cin>>t;
	while(t--){
		cin>>n>>a>>b>>c;
		ans=0;
		if(n==1) ans=0;
		else{
			int MIN=min(a,min(b,c));
			if(a==MIN){
				ans=(n-1)*a;
			}
			else if(b==MIN){
				ans=(n-1)*b;
			}
			else{
				ans=min(a,b)+(n-2)*c;
			}
		}
		cout<<ans<<endl;
	}
}