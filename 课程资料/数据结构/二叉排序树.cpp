/********************************
�ƿ�162
�º���
16401010225

����������
2017/11/2 

********************************/ 

#include<iostream>
#include<fstream>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

struct node{
	int data;
	node *Father;
	node *Right;
	node *Left;
};

int bst[10]={4,9,0,1,8,6,3,5,2,7};
int bst1[10];

void DispBTNode(node *Tree){                 //��ӡ������ 
	if(Tree!=NULL){
		cout<<Tree->data;
	}
	if(Tree->Left!=NULL||Tree->Right!=NULL){
		cout<<'(';
		if(Tree->Left!=NULL){
			DispBTNode(Tree->Left);
		}
		if(Tree->Left!=NULL&&Tree->Right==NULL){
			cout<<')';
		}
		if(Tree->Right!=NULL){
			cout<<',';
			DispBTNode(Tree->Right);
			cout<<')';
		}
	}
}

node *Creat(int bst[],int n){
	node *Tree=NULL;
	for(int i=0;i<n;i++){
		node *p=new node;
		p->data=bst[i];
		p->Father=NULL;
		p->Left=NULL;
		p->Right=NULL;
		if(i==0){
			Tree=p;
		}
		else{
			node *temp=Tree;
			while(1){
				if(p->data>=temp->data){
					if(temp->Right==NULL){
						p->Father=temp;
						temp->Right=p;
						break;
					} 
					else{
						temp=temp->Right;
					}
				}
				else if(p->data<temp->data){
					if(temp->Left==NULL){
						p->Father=temp;
						temp->Left=p;
						break;
					}
					else{
						temp=temp->Left;
					}
				}
			}
		}
		cout<<"    ��"<<i+1<<"��,����"<<bst[i]<<":";
		DispBTNode(Tree);
		cout<<endl;
	}
	return Tree;
}



bool Judge(node *Tree){
	node *pl,*pr;
	bool L,l,R,r;
	L=R=l=r=false;
	if(Tree==NULL){
		return true;
	}
	pl=Tree->Left;
	pr=Tree->Right;
	if(pl==NULL||(pl->data<Tree->data)){
		l=true;
	}
	if(pr==NULL||(pr->data>=Tree->data)){
		r=true;
	}
	L=Judge(pl);
	R=Judge(pr);
	
	return (L&&R&&l&&r);
}

node *Find1(node *Tree,int n){
	if(Tree==NULL){
		cout<<"�Ҳ���"<<n<<"�ڵ�"<<endl; 
		return NULL;
	}
	else if(Tree->data==n){
		cout<<Tree->data<<" ";
		return Tree;
	}
	else if(Tree->data>n){
		cout<<Tree->data<<" ";
		Find1(Tree->Left,n);
	}
	else{
		cout<<Tree->data<<" ";
		Find1(Tree->Right,n);
	}
}

node *Find2(node *Tree,int n){
	stack<node*>s;
	s.push(Tree);
	while(1){
		node *p=s.top();
		if(p==NULL) break;
		else if(p->data==n){
			break;
		}
		else if(p->data>n){
			s.push(p->Left);
		}
		else{
			s.push(p->Right);
		}
	}
	node *Find=NULL;
	while(!s.empty()){
		node *p=s.top();
		s.pop();
		if(p==NULL){
			cout<<"�Ҳ����ڵ�"<<n<<endl; 
			return NULL;
			break;
		}
		else{
			cout<<p->data<<" ";
			if(p->data==n){
				Find=p;
			}
		}
	}
	return Find;
} 

void DeleteNode(node *Tree){
	if(Tree->Left==NULL&&Tree->Right==NULL){
		if(Tree->Father->data > Tree->data){
			Tree->Father->Left=NULL;
		}
		else{
			Tree->Father->Right=NULL;
		}
		Tree=NULL;
	}
	else if(Tree->Left==NULL){
		if(Tree->Father->data > Tree->data){
			Tree->Father->Left=Tree->Right;
			Tree->Right->Father=Tree->Father;
		}
		else{
			Tree->Father->Right=Tree->Right;
			Tree->Right->Father=Tree->Father;
		}
		delete Tree;
	}
	else if(Tree->Right==NULL){
		if(Tree->Father->data > Tree->data){
			Tree->Father->Left=Tree->Left;
			Tree->Left->Father=Tree->Father;
		}
		else{
			Tree->Father->Right=Tree->Left;
			Tree->Left->Father=Tree->Father;
		}
		delete Tree;
	}
	else{
		node *flag=Tree;
		node *p=Tree->Left;
		while(p->Right!=NULL){
			flag=p;
			p=p->Right;
		}
		Tree->data=p->data;
		if(flag==Tree){
			flag->Left=p->Left;
			p->Father=flag;
		}
		else{
			flag->Right=p->Left;
			p->Father=flag;
		}
		delete p;
	}
}

void Delete(node *Tree,int n){
	if(Tree==NULL){
		cout<<"�Ҳ����ڵ�"<<n<<endl; 
	}
	else if(Tree->data==n){
		DeleteNode(Tree);
	}
	else if(Tree->data > n){
		Delete(Tree->Left,n);
	}
	else{
		Delete(Tree->Right,n);
	}
}

int main(){
	cout<<"ԭ���ݣ�";
	for(int i=0;i<10;i++) cout<<bst[i]<<" "; cout<<endl<<endl;
	
	cout<<"����������������"<<endl;
	node *Tree=NULL;
	Tree=Creat(bst,10);cout<<endl;
	
	cout<<"BST:";
	DispBTNode(Tree);cout<<endl<<endl;
	
	cout<<"�ж��Ƿ��Ƕ���������:";
	if(Judge(Tree)) cout<<"����һ�Ŷ���������"<<endl;
	else cout<<"�ⲻ��һ�Ŷ���������"<<endl; 
	cout<<endl;
	
	cout<<"����6�ؼ���(�ݹ�):";
	node *F1=NULL;
	F1=Find1(Tree,6);cout<<endl<<endl;
	
	cout<<"����6�ؼ���(�ǵݹ�):";
	node *F2=NULL;
	F2=Find2(Tree,6);cout<<endl<<endl;
	
	cout<<"ɾ������"<<endl;
	cout<<"    ԭBST:"; DispBTNode(Tree); cout<<endl;
	cout<<"    ɾ���ڵ�4:"; Delete(Tree,4); DispBTNode(Tree); cout<<endl;
	cout<<"    ɾ���ڵ�5:"; Delete(Tree,5); DispBTNode(Tree); cout<<endl;
	
	
} 
