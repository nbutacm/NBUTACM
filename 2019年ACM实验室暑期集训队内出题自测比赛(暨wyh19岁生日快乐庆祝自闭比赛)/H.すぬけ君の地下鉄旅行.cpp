
/*************************初中生代码=********************************************************************************/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define pa pair<int, int>
 
using namespace std;
 
const int MAXN = 1000010;
int dis[MAXN];
vector<pa> g[MAXN];
vector<int> new_g[MAXN], all[MAXN];
int visit[MAXN], ptr[MAXN];
queue<int> q;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        u--, v--;
        g[u].push_back(make_pair(c, v));
        g[v].push_back(make_pair(c, u));
        all[c].push_back(u);
        all[c].push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        sort(g[i].begin(), g[i].end());
        visit[i] = -1;
    }
    int newn = n;
    for (int i = 0; i < MAXN; i++)
    {
        if (all[i].empty())
        {
            continue;
        }
        for (int it = 0; it < all[i].size(); it++)
        {
            int v = all[i][it];
            if (visit[v] == i)
            {
                continue;
            }
            q.push(v);
            visit[v] = i;
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                while (ptr[x] < (int)g[x].size())
                {
                    int c = g[x][ptr[x]].first;
                    if (c != i)
                    {
                        break;
                    }
                    int u = g[x][ptr[x]].second;
                    if (visit[u] != i)
                    {
                        visit[u] = i;
                        q.push(u);
                    }
                    ptr[x]++;
                }
                new_g[x].push_back(newn);
                new_g[newn].push_back(x);
            }
            newn++;
        }
    }
    for (int i = 0; i < newn; i++)
    {
        dis[i] = -2;
    }
    q.push(0);
    dis[0] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < new_g[x].size(); i++)
        {
            int u = new_g[x][i];
            if (dis[u] == -2)
            {
                dis[u] = dis[x] + 1;
                q.push(u);
            }
        }
    }
    cout << dis[n - 1] / 2;
    return 0;
}
/*************************网上代码********************************************************************************/

 
#include<set>  
#include<map>  
#include<stack>  
#include<cstdio>  
#include<queue>  
#include<cmath>  
#include<vector>  
#include<climits>  
#include<cstring> 
#include<iostream> 
#include<algorithm> 
using namespace std;
#define INF 0x3f3f3f3f
#define LL long long
int read(){ 
    int f=1,x=0; 
    char c=getchar(); 
    while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();} 
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();} 
    return f*x; 
}
#define MAXN 2200000
struct edge{
    int v,w;
    edge(){}
    edge(int V,int W){v=V,w=W;}
};
int n,m;
struct node{
    int u,k;
    node(){}    
    node(int U,int K){u=U,k=K;}
    friend bool operator < (node a,node b){return a.u==b.u?a.k<b.k:a.u<b.u;}
};
struct node1{
    int u,v,k;
    node1(){}   
    node1(int U,int V,int K){u=U,v=V,k=K;}
};
vector<node> Make_zx;
vector<node1> Make_xx;
vector<edge> G[MAXN+5];
int dis[MAXN+5];
bool vis[MAXN+5];
queue<int>Q;
int SPFA(int S,int T){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[S]=0,vis[S]=1,Q.push(S);
    while(!Q.empty()){
        int u=Q.front(),v,w,siz=G[u].size();
        Q.pop();
        vis[u]=0;
        for(int i=0;i<siz;i++){
            v=G[u][i].v,w=G[u][i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    vis[v]=1;
                    Q.push(v);
                }
            }
        }
    }
    return dis[T]==INF?-1:dis[T]/2;
}
int main(){
    n=read(),m=read();
    for(int i=1;i<=m;i++){
        int p=read()-1,q=read()-1,c=read()-1;
        Make_zx.push_back(node(p,c));
        Make_zx.push_back(node(q,c));
        Make_xx.push_back(node1(p,q,c));
        Make_xx.push_back(node1(q,p,c));
    }
    sort(Make_zx.begin(),Make_zx.end());
    for(int i=0;i<int(Make_zx.size());i++){
        G[n+i].push_back(edge(Make_zx[i].u,1));
        G[Make_zx[i].u].push_back(edge(n+i,1));
    }
    for(int i=0;i<int(Make_xx.size());i++){
        int l1=lower_bound(Make_zx.begin(),Make_zx.end(),node(Make_xx[i].u,Make_xx[i].k))-Make_zx.begin(),
        l2=lower_bound(Make_zx.begin(),Make_zx.end(),node(Make_xx[i].v,Make_xx[i].k))-Make_zx.begin();
        G[l1+n].push_back(edge(l2+n,0));
    }
    printf("%d\n",SPFA(0,n-1));
    return 0;
}

/*************************兔子代码********************************************************************************/


#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
const int N=3e5+100,M=6e5+100;
int head[N],ver[M],edge[M],Next[M],d[N];
bool v[N];
int n,m,tot;
priority_queue<pair<int,int>>q;
void add(int x,int y,int z)
{
    ver[++tot]=y;
    edge[tot]=z;
    Next[tot]=head[x];
    head[x]=tot;
}
void dijkstra()
{
    int f=0;
    memset(d,0x3f3f3f3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[1]=0;
    q.push(make_pair(0,1));
    while(q.size())
    {
        //int f=0;
        int x=q.top().second;
        q.pop();
        if(v[x]) continue;
        v[x]=1;
        for(int i=head[x];i;i=Next[i])
        {   
            int y=ver[i],z;
            if(f!=edge[i]||f==0)
            {
                z=1;
                f=edge[i];
            }
            else z=0;
            if(d[y]>d[x]+z)
            {
                d[y]=d[x]+z;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    memset(head,0,sizeof(head));
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    dijkstra();
    if(d[n]==(0x3f3f3f3f)) cout<<-1<<endl;
    else cout<<d[n]<<endl;
     
     
    return 0;
}