#include<iostream>
using namespace std;

int a,b;
int sum;

int main(){
	while(cin>>a>>b){
		a=a*100;
		sum=0;
		for(int i=0;i<100;i++){    //ע��100�ǲ���ȡ����
			if((a+i)%b==0){
				sum++;
			}
		}
		cout<<sum<<endl;
	}
} 





