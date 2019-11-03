/******************************************/
//利用map进行打表 

#include<iostream>
#include<map>
using namespace std;

map<int,int>m;    //记录第i位置是1还是0 
int n,t;

void init(){
	m[1]=1;
	m[2]=1;
	for(int i=4,j=1;i<=1e9+5;j++,i++,i=i+j){
		m[i]=1;
	}
}

int main(){
	init();
	cin>>t;
	while(t--){
		cin>>n;
		cout<<m[n]<<endl;
	}
}

/***********************************************/   
#include<iostream>
#include<map>
using namespace std;

int a[50000];   //记录第i个1是在第几个位置 
int n,t;

int init(){
	a[1]=1;
	a[2]=2;
	int i;
	for(i=3;a[i-1]<=1e9;i++){
		a[i]=a[i-1]+(i-1);
	}
	return i;
}

int binary(int l,int r,int k){
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==k) return 1;
		if(a[mid]>k) r=mid-1;
		if(a[mid]<k) l=mid+1;
	}
	return 0;
}

int main(){
	int cnt=init();
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans=binary(1,cnt,n);
		printf("%d\n",ans);
	}
}


/**************************************************/

//纯粹的数学的方法
 
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int T;
    int N;

    cin >> T;
    while (T--)
    {
        scanf("%d", &N);
        int m = sqrt((N - 1) * 2);
        if (m*(m + 1) == (N - 1) * 2)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }

    return 0;
} 
