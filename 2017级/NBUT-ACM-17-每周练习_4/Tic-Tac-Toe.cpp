#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int t;
char pic[10][10];
char o;

bool check(int x,int y,char o){
	int all=0;
	//先横着来
	int num=0;
	for(int i=0;i<5;i+=2){
		if(pic[x][i]==o) num++;
	}
	if(num==3) return true;
	else if(num>=2) all++;
	//再竖着来 
	num=0;
	for(int i=0;i<3;i++){
		if(pic[i][y]==o) num++;
	}
	if(num==3) return true;
	else if(num>=2) all++;
	//再斜着来
	//先从左上到右下 
	num=0;
	if((x==0&&y==0)||(x==2&&y==4)||(x==1&&y==2)){
		for(int i=0;i<3;i++){
			if(pic[i][i*2]==o) num++;
		}
	}
	if(num==3) return true;
	else if(num>=2) all++;
	//再从左下到右上 
	num=0;
	if((x==2&&y==0)||(x==0&&y==4)||(x==1&&y==2)){
		for(int i=0;i<3;i++){
			if(pic[i][4-i*2]==o) num++;
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
			gets(pic[i]);
		}
		cin>>o;
		bool flag=false;
		for(int i=0;i<3;i++){
			for(int j=0;j<5;j+=2){
				if(pic[i][j]=='.'){
					pic[i][j]=o;
					flag=check(i,j,o);
					pic[i][j]='.';
					if(flag==true) break; 
				}
			}
			if(flag==true) break; 
		}
		if(flag==true) cout<<"Kim win!"<<endl;
		else cout<<"Cannot win!"<<endl;
	}
} 
