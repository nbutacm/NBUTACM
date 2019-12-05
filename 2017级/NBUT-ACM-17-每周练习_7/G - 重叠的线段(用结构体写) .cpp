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
	sort(a,a+n,cmp);      //根据线段的结尾升序排序 

	stuff flag=a[0];
	for (int i=1;i<n;i++){                //每两条线段就三种情况 
		if(flag.end<=a[i].start){         //第一种 两条线段没有重合 
			flag=a[i];
		}
		else if(flag.end>=a[i].end){          //第二种 两条线段完全重合 
			Max=max(Max,a[i].end-a[i].start);
		}
		else if(flag.end<=a[i].end){          //第三种 两条线段 部分重合 
			Max=max(Max,flag.end-a[i].start);
			flag=a[i];
		}
	
	}

	cout<<Max<<endl;
	return 0;
}
