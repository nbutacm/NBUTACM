#include<iostream>
#include <stdio.h>
#include<io.h>
#include<string>
#include <string.h>
#include<vector>
#include<fstream>
using namespace std;

struct node{
	string name;
	int size;
	node *father; 
	vector<node*>son;
};

string FindFather(string str){
	string ans;
	int len=str.size();
	for(int i=len-1;;i--){
		if(str[i]=='\\') break;
		ans=str[i]+ans;
	}
	return ans;
}

void FindFire(string FileName,node *Tree){
	struct _finddata_t fa;
    long fHandle=_findfirst( (FileName+"\\*.*").c_str(), &fa );
    if(fHandle!=-1L){
    	do{
    		if(strcmp(fa.name,".")==0||strcmp(fa.name,"..")==0) continue;
    		node *p=new node;
    		p->name=fa.name;
    		p->father=Tree;
    		p->size=fa.size;
    		p->son.clear();
    		Tree->son.push_back(p);
    		printf( "找到文件的爸爸:%s\n", FindFather(FileName).c_str() );
	        printf( "找到文件:%s\n", fa.name );
	        printf( "找到文件的大小:%d\n", fa.size );
	        FindFire(FileName+"\\"+fa.name,p); 
	    }while( _findnext(fHandle,&fa)==0 );
	    
    } 
	_findclose( fHandle );
}

void PrintTree(node *Tree,int n,ofstream &file){
	for(int i=0;i<n;i++) file<<"\t";
	if(Tree->father==NULL) file<<"/"<<Tree->name<<endl;
	else file<<Tree->name<<endl;
	for(int i=0;i<Tree->son.size();i++){
		PrintTree(Tree->son[i],n+1,file);
	}
}

int CalculateTree(node *Tree){
	int ans=0;
	ans=Tree->size;
	for(int i=0;i<Tree->son.size();i++){
		ans+=CalculateTree(Tree->son[i]);
	}
	return ans;
}

int main()
{
	int Size=0;
    node *Tree=new node;
    Tree->name="user";
    Tree->size=0;
    Tree->father=NULL;
    Tree->son.clear();
    ofstream file("out.txt");
   	FindFire("user",Tree);
   	PrintTree(Tree,0,file);
   	Size=CalculateTree(Tree);
   	file.close();
   	cout<<"文件的大小为： "<<Size<<endl;
    return 0;
}


//"D:\\user\\*.*" 
