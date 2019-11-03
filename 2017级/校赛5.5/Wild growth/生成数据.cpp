#include<bits/stdc++.h>
using namespace std;
const int maxn =1e8;
int main(){
	ofstream fin("in.txt",ios::app);
	srand((unsigned)time(NULL));
	for(int i=0;i<10;i++){
		int x=rand()%maxn*rand()%maxn;
		int y=rand()%maxn*rand()%maxn;
		int z=rand()%maxn*rand()%maxn;
		cout<<x<<" "<<y<<" "<<z<<endl;
	}
} 
