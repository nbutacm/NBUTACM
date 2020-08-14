#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#define pi acos(-1.0)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
vector<int> maze1[1100];
vector<int> maze2[1100];
int vis[1100];
int vist[1100];
int ans[1100];
int bck[1100];/*bfs能到达的点*/
int cnt=0;
int res=0;
int bfs()
{
    queue<int> q;
    vis[1]=1;
    bck[cnt++]=1;
    q.push(1);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();//放后面会超时
        if(maze1[x].size()==0)
        {
            res++;//机器人停在红线链接的地图上（即这个点不指向其他点 可能会存在点但是此点与其他点的连线为黑线）
            vis[x]=1;
            continue;
        }
        for(int i=0;i<maze1[x].size();i++)// 二维vector 表示 x点指向多少个点
        {
            if(vis[maze1[x][i]])
                continue;
            vis[maze1[x][i]]=1;
            q.push(maze1[x][i]);
            bck[cnt++]=maze1[x][i];
        }
         
    }
}
void dfs(int x)
{
    if(vist[x] || vis[x])
        return ;
    if(maze1[x].size()==0)//表示经过一次bug后又一次经过红线链接的点
    {
        ans[x]=1;//标记停止的点
        return;
    }
    vist[x]=1;
    for(int i=0;i<maze1[x].size();i++)
    {
        dfs(maze1[x][i]);
        vist[x]=0;
    }
}
int main()
{
    int x,y;
    int n,m;
    scanf("%d%d",&n,&m);
    ms(vis,0);
    ms(vist,0);
    ms(ans,0);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        if(x<0)
            maze1[-x].push_back(y);//红线地图
        else
            maze2[x].push_back(y);//黑线地图
    }
    bfs();
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<maze2[bck[i]].size();j++)
        {
            dfs(maze2[bck[i]][j]);//首次dfs按照黑线地图（因为只能有一个bug）传入的是与红点通过黑点相连的另一个点 (也可能没有点) 
        }
    }
    for(int i=1;i<=n;i++)
        if(ans[i])
            res++;
    printf("%d\n",res);
    return 0;
}
