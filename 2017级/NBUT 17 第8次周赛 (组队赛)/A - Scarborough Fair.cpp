//A - Scarborough Fair    CodeForces - 897A
// ��l-r֮���c1����c2
//ע�� l��r ����1 ��ʼ�ģ����ַ����±�����0��ʼ�� 

#include<iostream>
#include<string>
using namespace std;

int n,m;
string s;
int l,r;
char c1,c2;

int main(){
	cin>>n>>m;
	cin>>s;
	while(m--){
		cin>>l>>r>>c1>>c2;
		for(int i=l;i<=r;i++){
			if(s[i-1]==c1) s[i-1]=c2;
		}
	}
	cout<<s<<endl;
}
