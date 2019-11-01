#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

int a,b;

int main(){
	srand(time(0));
	freopen("data.in","w",stdout);
	
	int t=1000;
	while(t--){
		a=rand()%10000+1;
		b=10+rand()%90;
		cout<<a<<" "<<b<<endl;
	}
}
