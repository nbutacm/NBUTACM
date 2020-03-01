#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 35;
typedef struct {
	int x, y, z, step;
}node;
int dir[6][3] ={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
char mp[maxn][maxn][maxn];
int F[maxn][maxn][maxn], l, r, c; 
node startnode, endnode;
int bfs()
{
	int i;
	queue<node> q;
	node p, tp;
	p = startnode;
	F[p.x][p.y][p.z] = 1;
	q.push(p);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (endnode.x == p.x && endnode.y == p.y && endnode.z == p.z)
			return p.step;
		for (i = 0; i < 6; i++)
		{
			tp.x = p.x + dir[i][0];
			tp.y = p.y + dir[i][1];
			tp.z = p.z + dir[i][2];
			if (tp.x >= 0 && tp.x < l && tp.y >= 0 && tp.y < r && tp.z >= 0 && tp.z < c)
			{
				if(F[tp.x][tp.y][tp.z] == 1 || mp[tp.x][tp.y][tp.z] == '#')
                	continue;
                F[tp.x][tp.y][tp.z] = 1;
                tp.step = p.step + 1;
                q.push(tp);
			}
		}
	}
	
	return 0;	
}

int main(void)
{
	int i, j, k;
	while (cin >> l >> r >> c && (l || r || c))
	{
		memset(F, 0, sizeof(F));
		for (i = 0; i < l; i++)
		{
			for (j = 0; j < r; j++)
			{
				for (k = 0; k < c; k++)
				{
					cin >> mp[i][j][k];
					if (mp[i][j][k] == 'S')	
					{
						startnode.x = i;
						startnode.y = j;
						startnode.z = k;
						startnode.step = 0;	
					}
					if (mp[i][j][k] == 'E')	
					{
						endnode.x = i;
						endnode.y = j;
						endnode.z = k;
						endnode.step = 0;	
					}
				}
			}	
		}
		
		int cnt = bfs();
		if (cnt)
			printf("Escaped in %d minute(s).\n",cnt);
		else
			printf("Trapped!\n");
	}
	
	return 0;	
}
