//Tic-Tac-Toe FZU - 2283 
//== ���� ==
//ģ���������¾����壬�ж��ܷ���������Ӯ�ñ��� 

//== ��� ==
//���ڿ����µĵط���һ�ӣ�Ȼ���ж��������б�������ˣ���ֱ��Ӯ�����ߺ���б���������������������ӣ���Ҳ��Ӯ 

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int t;
char pic[10][10];
char o;

bool check(int x,int y,char o){
	int all=0;
	//�Ⱥ�����
	int num=0;
	for(int i=0;i<3;i++){
		if(pic[x][i]==o) num++;
	}
	if(num==3) return true;
	else if(num>=2) all++;
	//�������� 
	num=0;
	for(int i=0;i<3;i++){
		if(pic[i][y]==o) num++;
	}
	if(num==3) return true;
	else if(num>=2) all++;
	//��б����
	//�����ϵ����� 
	num=0;
	if((x==0&&y==0)||(x==1&&y==1)||(x==2&&y==2)){
		for(int i=0;i<3;i++){
			if(pic[i][i]==o) num++;
		}
	}
	if(num==3) return true;
	else if(num>=2) all++;
	//�����ϵ����� 
	num=0;
	if((x==2&&y==0)||(x==1&&y==1)||(x==0&&y==2)){
		for(int i=0;i<3;i++){
			if(pic[i][2-i]==o) num++;
		}
	}
	if(num==3) return true;
	else if(num>=2) all++;
	
	if(all>=2) return true;
	else return false;
}

int main(){
	cin>>t;
	while(t--){
		getchar();
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cin>>pic[i][j];
			}
		}
		cin>>o;
		bool flag=false;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(pic[i][j]=='.'){
					pic[i][j]=o;           //��������һ�� 
					flag=check(i,j,o);
					pic[i][j]='.';         //������оͱ���� 
					if(flag==true) break; 
				}
			}
			if(flag==true) break; 
		}
		if(flag==true) cout<<"Kim win!"<<endl;
		else cout<<"Cannot win!"<<endl;
	}
} 
