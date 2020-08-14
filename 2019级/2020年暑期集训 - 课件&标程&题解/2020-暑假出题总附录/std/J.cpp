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
int bck[1100];/*bfs�ܵ���ĵ�*/
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
        q.pop();//�ź���ᳬʱ
        if(maze1[x].size()==0)
        {
            res++;//������ͣ�ں������ӵĵ�ͼ�ϣ�������㲻ָ�������� ���ܻ���ڵ㵫�Ǵ˵��������������Ϊ���ߣ�
            vis[x]=1;
            continue;
        }
        for(int i=0;i<maze1[x].size();i++)// ��άvector ��ʾ x��ָ����ٸ���
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
    if(maze1[x].size()==0)//��ʾ����һ��bug����һ�ξ����������ӵĵ�
    {
        ans[x]=1;//���ֹͣ�ĵ�
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
            maze1[-x].push_back(y);//���ߵ�ͼ
        else
            maze2[x].push_back(y);//���ߵ�ͼ
    }
    bfs();
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<maze2[bck[i]].size();j++)
        {
            dfs(maze2[bck[i]][j]);//�״�dfs���պ��ߵ�ͼ����Ϊֻ����һ��bug�������������ͨ���ڵ���������һ���� (Ҳ����û�е�) 
        }
    }
    for(int i=1;i<=n;i++)
        if(ans[i])
            res++;
    printf("%d\n",res);
    return 0;
}
