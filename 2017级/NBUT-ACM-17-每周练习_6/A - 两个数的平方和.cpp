#include<iostream>
#include<math.h>
using namespace std;


int main(){
	int n;
	bool flag=true;
	
	cin>>n;
	for(int i=0;i*i<=n;i++){           //i Ҫ�� �� 00000000  ��ʼ 
		int j=sqrt((double)(n-i*i));
		if(j*j+i*i==n&&i<=j){
			cout<<i<<" "<<j<<endl;
			flag=false;
		}
	}
	if(flag==true) cout<<"No Solution"<<endl;
	
	return 0;
}
