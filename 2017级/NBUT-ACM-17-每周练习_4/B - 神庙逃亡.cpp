#include<iostream>
using namespace std;

int n;
double s,h,vx,vy;

int main(){
	cin>>n;
	while(n--){
		cin>>s>>h>>vx>>vy;
		double t=s/vx;
		double h1=vy*t-0.5*10*t*t;
		if(h1>=h) cout<<"good done!"<<endl;
		else cout<<"poor Merida!"<<endl;
	}
}
