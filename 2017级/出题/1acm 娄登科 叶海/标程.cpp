#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=500+5;
const int INF=0x3f3f3f3f;
int n,m,a,b;
int low[N],dis[N][N];
bool vis[N];
int Prim(){
	  memset(low,0x3f,sizeof(low));
      memset(vis,false,sizeof(vis));
       int ans=0,cnt=0;
      for(int i=1;i<=a;i++){
        low[i]=dis[1][i];
      }
      vis[1]=true;
   while(true){
          int k=-1;
           for(int i=1;i<=a;i++){
            if(!vis[i]&&(k==-1||low[k]>low[i]))
                k=i;
            }
        if(k==-1||low[k]==INF)
            break;
        vis[k]=true;
        ans+=low[k];
        cnt++;
        for(int i=1;i<=a;i++){
            if(low[i]>dis[k][i]){
                low[i]=dis[k][i];
            }
        }
    }
    if(cnt==a-1)
    	return ans;
    else
    	return -1;
}
int main(){
	scanf("%d",&n);
    while(n--){
    	scanf("%d%d%d",&m,&a,&b);
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=b;i++){
            int p1,p2,p3,p4;
            scanf("%d%d%d%d",&p1,&p2,&p3,&p4);
            if(p4>m)continue;
            if(p3<dis[p1][p2])
			 dis[p1][p2]=dis[p2][p1]=p3;
        }
        if(Prim()!=-1){
        cout<<"YES"<<endl;
        //cout << "正确" << endl;
		cout<<Prim()<<endl;
        }
		else{
		cout<<"NO"<<endl;
		//cout << "错误" << endl;
		}
    }
    return 0;
}
