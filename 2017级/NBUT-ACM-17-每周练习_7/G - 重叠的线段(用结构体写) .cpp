#include <iostream>
#include <algorithm>
using namespace std;

struct stuff{
	long long start;
	long long end;
}a[50005];

int cmp(stuff a,stuff b){
	return a.start<b.start;
} 

int main(){
	int n;
	long long Max=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i].start>>a[i].end;
	}
	sort(a,a+n,cmp);      //�����߶εĽ�β�������� 

	stuff flag=a[0];
	for (int i=1;i<n;i++){                //ÿ�����߶ξ�������� 
		if(flag.end<=a[i].start){         //��һ�� �����߶�û���غ� 
			flag=a[i];
		}
		else if(flag.end>=a[i].end){          //�ڶ��� �����߶���ȫ�غ� 
			Max=max(Max,a[i].end-a[i].start);
		}
		else if(flag.end<=a[i].end){          //������ �����߶� �����غ� 
			Max=max(Max,flag.end-a[i].start);
			flag=a[i];
		}
	
	}

	cout<<Max<<endl;
	return 0;
}
