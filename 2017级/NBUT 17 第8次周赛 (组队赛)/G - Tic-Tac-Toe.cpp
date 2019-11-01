//Tic-Tac-Toe FZU - 2283 
//== 题意 ==
//模拟两个人下井字棋，判断能否在两步内赢得比赛 

//== 题解 ==
//先在可以下的地方下一子，然后判断如果横竖斜有三颗了，就直接赢；或者横竖斜有至少两个方向有两个子，那也能赢 

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
	for(int i=0;i<3;i++){
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
	//从左上到右下 
	num=0;
	if((x==0&&y==0)||(x==1&&y==1)||(x==2&&y==2)){
		for(int i=0;i<3;i++){
			if(pic[i][i]==o) num++;
		}
	}
	if(num==3) return true;
	else if(num>=2) all++;
	//从右上到左下 
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
					pic[i][j]=o;           //尝试着下一步 
					flag=check(i,j,o);
					pic[i][j]='.';         //如果不行就变回来 
					if(flag==true) break; 
				}
			}
			if(flag==true) break; 
		}
		if(flag==true) cout<<"Kim win!"<<endl;
		else cout<<"Cannot win!"<<endl;
	}
} 
