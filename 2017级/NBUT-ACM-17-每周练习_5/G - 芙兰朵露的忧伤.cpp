#include <stdio.h>
#include <string.h>
char tu[210][210];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int vis[210][210];
int n,m;
void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&tu[nx][ny]==' '&&!vis[nx][ny])
        {
            dfs(nx,ny);
        }
    }
}
int main()
{
    int ans=0;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        getchar();
        memset(vis,0,sizeof(vis));
        ans=0;
        for(int i=0;i<n;i++)
        {
            gets(tu[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(tu[i][j]==' '&&!vis[i][j])
                {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
