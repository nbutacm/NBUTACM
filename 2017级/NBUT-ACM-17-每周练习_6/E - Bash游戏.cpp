#include<iostream>
using namespace std;
int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a%(b+1)==0) cout<<'B'<<endl;
		else cout<<'A'<<endl;
	}
	return 0;
}

//������1��,�����b��,�������a��(b+1)�ı���,��ô��������ȡ����,���־�һ�����Դճ�(1+b),���һ��һ���Ǻ��ֵ� 


//���ڲ��Ļ���֪ʶ���ܽ᣺��ʲ���ģ�Bash Game������ķ���ȣ�Nim Game�����������ȣ�Wythoff Game���� 
