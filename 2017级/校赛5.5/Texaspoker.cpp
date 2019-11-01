#include<iostream>
#include<algorithm>
using namespace std;

int type(int a[]){
	int num[15]={0};
	int _4,_3,_2;
	_4=_3=_2=0;
	
	for(int i=1;i<=5;i++) num[a[i]]++;

	for(int i=2;i<=14;i++){
		if(num[i]==4) _4++;
		if(num[i]==3) _3++;
		if(num[i]==2) _2++;
	}

	if(_4==1) return 7;
	if(_3==1&&_2==1) return 6;
	if(_3==1) return 4;
	if(_2==2) return 3;
	if(_2==1) return 2;

	for(int i=2;i<=5;i++){
		if(a[i-1]+1!=a[i]) return 1;
	}

	return 5;
}

int check1(int a[],int b[]){
	int a21,a22,a1;
	int b21,b22,b1;
	a21=a22=a1=b21=b22=b1;

	if(a[1]==a[2]||a[2]==a[3]) a21=a[1];
	if(a[3]==a[4]||a[4]==a[5]) a22=a[4];
	for(int i=1;i<=5;i++){
		if(a[i]!=a21&&a[i]!=a22) a1=a[i];
	}

	if(b[1]==b[2]||b[2]==b[3]) b21=b[1];
	if(b[3]==b[4]||b[4]==b[5]) b22=b[4];
	for(int i=1;i<=5;i++){
		if(b[i]!=b21&&b[i]!=b22) b1=b[i];
	}

	if(a22>b22) return 1;
	if(a22<b22) return -1;
	if(a21>b21) return 1;
	if(a21<b21) return -1;
	if(a1>b1) return 1;
	if(a1<b1) return -1;
	return 0;

}

int check2(int a[],int b[]){
	int a2,b2;
	for(int i=1;i<=4;i++){
		if(a[i]==a[i+1]){
			a2=a[i];
			a[i]=a[i+1]=15;
		}
	}

	for(int i=1;i<=4;i++){
		if(b[i]==b[i+1]){
			b2=b[i];
			b[i]=b[i+1]=15;
		}
	}

	sort(a+1,a+1+5);
	sort(b+1,b+1+5);

	if(a2>b2) return 1;
	if(a2<b2) return -1;
	for(int i=1;i<=3;i++){
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return -1;
	}
	return 0;
}

int check3(int a[],int b[]){
	for(int i=5;i>=1;i--){
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return -1;
	}
	return 0;
}

int main(){
	//freopen("/Users/cccccccccchy/compare/Texaspoker.in","r",stdin);  
    //freopen("/Users/cccccccccchy/compare/Texaspoker.out","w",stdout); 
	int t;
	int a[6];
	int b[6];
	cin>>t;
	while(t--){
		for(int i=1;i<=5;i++) cin>>a[i];
		for(int i=1;i<=5;i++) cin>>b[i];
		sort(a+1,a+1+5);
		sort(b+1,b+1+5);
		int typeA=type(a);
		int typeB=type(b);
		int flag=0;
		if(typeA>typeB) flag=1;
		if(typeA<typeB) flag=-1;
		if(typeA==typeB){
			if(typeA==7||typeA==6||typeA==4) flag=(a[3]>b[3]?1:-1);
			if(typeA==5){
				if(a[1]==b[1]) flag=0;
				if(a[1]>b[1]) flag=1;
				if(a[1]>b[1]) flag=-1;
			}
			if(typeA==3) flag=check1(a,b); 
			if(typeA==2) flag=check2(a,b); 
			if(typeA==1) flag=check3(a,b);
		}
		if(flag==1) cout<<"WIN"<<endl;
		if(flag==-1) cout<<"LOSE"<<endl;
		if(flag==0) cout<<"DRAW"<<endl;
	}
}