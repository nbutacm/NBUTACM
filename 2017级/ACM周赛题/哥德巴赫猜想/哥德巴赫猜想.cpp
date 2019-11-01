#include<iostream>
#include<math.h>
using namespace std;

int n,sum;
int a[100005];

bool isprime(int n){
	if(n==1||n==0) return false;
	for(int i=2;i<=sqrt(1.0*n);i++){
		if(n%i==0) return false;
	}
	return true;
}

void Init(){
	for(int i=0;i<=100000;i++){
		if(isprime(i)){
			a[i]=1;
		}
		else a[i]=0;
	}
}

int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	//Init();
	while(cin>>n){
		sum=0;
		for(int i=3;i<=n/2;i++){
			if(a[i]&&a[n-i]) sum++;
			//if(isprime(i)&&isprime(n-i)) sum++;
		}
		cout<<sum<<endl;
	}
} 
