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
		a=rand()%1000000000+1;
		cout<<a<<endl;
	}
}
