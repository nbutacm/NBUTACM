#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

int hash[250];

struct node{
	string S;
	node *Left;
	node *Right;
};

void Print(node *Tree){
	if(Tree!=NULL){
		Print(Tree->Left);
		Print(Tree->Right);
		cout<<Tree->S<<" ";
	}
}

double String_to_double(string s){
	double ans=0;
	double n=10;
	double m=1;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])) ans=ans*n+(s[i]-'0')*m;
		if(m<1) m=m*0.1;
		if(s[i]=='.'){
			n=1;
			m=0.1;
		}
	}
	return ans;
} 

double Calculaor(node *Tree){
	if(Tree!=NULL){
		if(Tree->S=="+") return Calculaor(Tree->Left)+Calculaor(Tree->Right);
		else if(Tree->S=="-") return Calculaor(Tree->Left)-Calculaor(Tree->Right);
		else if(Tree->S=="*") return Calculaor(Tree->Left)*Calculaor(Tree->Right);
		else if(Tree->S=="/") return Calculaor(Tree->Left)/Calculaor(Tree->Right);
		else return String_to_double(Tree->S);
	}
}

string Infix_to_Suffix(string s){
	string ans;
	stack<char>st;
	for(int i=0;i<s.size();i++){
		if(s[i]==' ') continue;
		else if(isdigit(s[i])){
			string str;
			while(isdigit(s[i])||s[i]=='.'){
				str=str+s[i];
				i++;
			}
			ans=ans+str+' ';
			i--;
		}
		else{
			if(s[i]=='(') st.push(s[i]);
			else if(s[i]==')'){
				while(!st.empty()){
					char o=st.top();
					st.pop();
					if(o=='(') break;
					ans=ans+o+' ';
				}
			}
			else{
				while(!st.empty()){
					char o=st.top();
					st.pop();
					if(o=='('){
						break;
					}
					if(hash[s[i]]<hash[o]){
						ans=ans+o+' ';
					}
				}
				st.push(s[i]);
			}
		}
	}
	while(!st.empty()){
		char o=st.top();
		st.pop();
		ans=ans+o+' ';
	}
	return ans;
}

int main(){
	hash['+']=hash['-']=1;
	hash['*']=hash['/']=2;
	//string s1="(1.33+2)*3";
	//string s=Infix_to_Suffix(s1);
	//cout<<s<<endl; 
	string str;
	fstream fin("A1.txt",ios::in);
	fstream fout("A1_out.txt",ios::out);
	while(getline(fin,str)){
		cout<<"前缀表达式： "<<str<<endl; 
		string s=Infix_to_Suffix(str);
		cout<<"后缀表达式： "<<s<<endl; 
		stack<node *>st;
		for(int i=0;i<s.size();i++){
			if(s[i]==' ') continue;
			node *p=new node;
			p->S="";
			p->Left=NULL;
			p->Right=NULL;
			if(isdigit(s[i])){
				string str;
				while(isdigit(s[i])||s[i]=='.'){
					str=str+s[i];
					i++;
				}
				p->S=str;
			}
			else{
				p->S=s[i];
				node *pright=st.top();st.pop();
				node *pleft=st.top();st.pop();
				p->Left=pleft;
				p->Right=pright;
			}
			st.push(p);
		}
		node *Tree=st.top();st.pop();
		//Print(Tree);
		//cout<<endl;
		cout<<"结果： "<<str<<" = "<<Calculaor(Tree)<<endl<<endl; 
		fout<<str<<" = "<<Calculaor(Tree)<<endl;
	}
	fin.close();
	fout.close();
}
