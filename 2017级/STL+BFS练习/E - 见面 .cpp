#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

int gx,gy,n,m;
int vis[12][12];
char Map[12][12];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
struct node{
    int x,y,step;
};

int bfs(int sx,int sy){
    memset(vis,0,sizeof(vis));
    queue <node> Q;
    node now,tmp;
    tmp.x=sx;tmp.y=sy;tmp.step=0;
    Q.push(tmp);
    vis[sx][sy]=1;
    while(!Q.empty()){
        now=Q.front();Q.pop();
        if(now.x==gx&&now.y==gy) return now.step;
        for(int i=0;i<4;i++){
            tmp.x=now.x+dx[i];
            tmp.y=now.y+dy[i];
            if(tmp.x>=1&&tmp.x<=n&&tmp.y>=1&&tmp.y<=m&&!vis[tmp.x][tmp.y]&&Map[tmp.x][tmp.y]!='*'){
                vis[tmp.x][tmp.y]=1;
                tmp.step=now.step+1;
                Q.push(tmp);
            }
        }
    }
    return -1;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>Map[i][j];
                if(Map[i][j]=='m') gx=i,gy=j;
            }
        }
        int t1=bfs(1,1),t2=bfs(n,m);
        if(t1==-1||t2==-1) cout<<-1<<endl;
        else if(t1==t2) cout<<0<<endl;
        else if(t1<t2) cout<<1<<endl;
        else if(t1>t2) cout<<2<<endl;
    }
    return 0;
}
