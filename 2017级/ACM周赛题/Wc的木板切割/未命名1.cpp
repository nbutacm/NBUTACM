#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

int n;
int a[1005];

int cmp(int a,int b){
	return a>b;
}

struct cmp1  
{  
     bool operator ()(int x, int y)  
    {  
        return x > y;//С�����ȼ���  
    }  
};  

int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	while(cin>>n){
		memset(a,0,sizeof(a));
		/*********************************************
		
		priority_queue<int,vector<int>, cmp1>q;              //���ȶ���ģ��  
		for(int i=0;i<n;i++){
			cin>>a[i];
			q.push(a[i]);
		}
		int ans=0;
		while(q.size()>1){
			int m1=q.top();q.pop();
			int m2=q.top();q.pop();
			ans+=m1+m2;
			q.push(m1+m2);
		}
		cout<<ans<<endl;
		**************************************************/
		
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int N=n;
		int ans=0;
		while(N>=2){ 
			sort(a,a+N,cmp);      //�Զ���cmp������ʹ��Ӵ�С�� 
			int m1=a[N-1],m2=a[N-2];  //m1Ϊ��С��m2Ϊ��С
			int t=m1+m2;
			ans+=t;
			a[N-2]=t;
			N--;
		}
		cout<<ans<<endl;
		

	}
}
