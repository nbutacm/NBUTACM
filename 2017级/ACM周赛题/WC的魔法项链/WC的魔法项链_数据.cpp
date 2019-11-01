#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

int n,k;

int main(){
	srand(time(0));
	freopen("data.in","w",stdout);
	
	int t=10;
	while(t--){
		n=rand()%100+1;
		while(1){
			k=rand()%100+1;
			if(k<=n) break;
		}
		cout<<n<<" "<<k<<endl;
		for(int i=0;i<n;i++){
			if(i==0) cout<<rand()%10000+1;
			else cout<<" "<<rand()%10000+1;
		}
		cout<<endl;
	}
}
