#include<iostream>
using namespace std;

void Scan(int a[][4],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
}

void Print(int a[][4],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j]<<(j==m-1?"\n":" ");
		}
	}
}

void Transpose(int a[][4],int n,int m,int c[][4]){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c[i][j]=a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<m;j++){
			swap(c[i][j],c[j][i]);
		}
	}
}

void Add(int a[][4],int b[][4],int n,int m,int c[][4]){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
}

void PrintUnderTheTriangle(int A[][4],int n,int m,int a[],int &cnt){
	cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			a[cnt++]=A[i][j];
		}
	}
	for(int i=0;i<cnt;i++){
		cout<<a[i]<<(i==cnt-1?"\n":" ");
	}
}

void Mul(int a[][4],int b[][4],int n,int c[][4]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				c[i][j]+=a[i][k]*b[k][i];
			}
		} 
	}
}

int main(){
	freopen("in1.txt","r",stdin);
	int A[4][4]={0};
	int B[4][4]={0};
	int C[4][4]={0};
	int D[4][4]={0};
	int a[16]={0};
	int b[16]={0};
	int cnt=0;
	int n,m;
	cout<<"输入矩阵的行和列："<<endl;
	cin>>n;
	cout<<"A的原始矩阵"<<endl;
	Scan(A,n,n);
	Print(A,n,n);
	cout<<"B的原始矩阵"<<endl;
	Scan(B,n,n);
	Print(B,n,n);
	cout<<"A的下三角元素"<<endl;
	PrintUnderTheTriangle(A,n,m,a,cnt);
	cout<<"B的下三角元素"<<endl;
	PrintUnderTheTriangle(B,n,m,b,cnt);
	cout<<"A的转置矩阵"<<endl;
	Transpose(A,n,n,C); 
	Print(C,n,n);
	cout<<"A+B"<<endl;
	Add(A,B,n,n,C);
	Print(C,n,n);
	cout<<"A*B"<<endl;
	Mul(A,B,n,D);
	Print(D,n,n);
}
