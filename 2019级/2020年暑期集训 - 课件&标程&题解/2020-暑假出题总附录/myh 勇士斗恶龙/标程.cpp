#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
using namespace std;
#define goup(i,a,b) for(int i=a;i<b;i++)
#define Goup(i,a,b) for(int i=a;i<=b;i++)
#define godown(i,a,b) for(int i=a;i>b;i--)
#define Godown(i,a,b) for(int i=a;i>=b;i--)
#define Gohead(i,a) for(int i=head[a];i;i=nxt[i])
#define memsetfa(n) for(int i=0;i<=n;i++)fa[i]=i
#define memsetmin(i) memset(i,0,sizeof(i))
#define memsetmax(i) memset(i,0x3f3f3f,sizeof(i))
typedef long long ll;
//const int dir[9][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
const int dir[9][2] = { {-1,0},{1,0},{0,-1},{0,1} };
const int dirr[9][2] = { {1,0},{-1,0},{0,1},{0,-1} };
const int Mod = 1e9 + 7;
int n, m, r, sx, sy, len, ans, snake, book[16][16][65555];
char s[25][25];
struct node
{
	int x, y, z;
	node(const int &x, const int &y, const int &z) :x(x), y(y), z(z) {};
};
bool bomb(int x, int y)
{
	return x >= 1 && y >= 1 && x <= n && y <= m && s[x][y] != '#';
}
bool dead(int x, int y, int z)
{
	int a = x, b = y, type;
	Godown(i, len - 2, 0)
	{
		type = (z >> 2 * i) % 4;
		a += dir[type][0], b += dir[type][1];
		if (a == x && b == y)
		{
			return 0;
		}
	}
	return 1;
}
void init(int x, int y)
{
	Goup(i, 0, 3)
	{
		int a = x + dir[i][0], b = y + dir[i][1];
		if (s[a][b] == s[x][y] + 1)
		{
			len++;
			snake = (snake << 2) + i;
			init(a, b);
		}
	}
}
int bfs(int x, int y, int z)
{
	queue<node>now, ready;
	now.emplace(x, y, z);
	while (!now.empty())
	{
		ans++;
		while (!now.empty())
		{
			node l = now.front();
			now.pop();
			Goup(i, 0, 3)
			{
				int a = l.x + dirr[i][0], b = l.y + dirr[i][1];
				int c = (l.z >> 2) + (i << 2 * (len - 2));
				if (s[a][b] == '@')
				{
					return ans;
				}
				if (bomb(a, b) && dead(a, b, c) && book[a][b][c] == 0)
				{
					book[a][b][c] = 1;
					ready.emplace(a, b, c);
				}
			}
		}
		while (!ready.empty())
		{
			now.push(ready.front());
			ready.pop();
		}
	}
	return -1;
}
int main()
{
	while (cin >> n >> m)
	{
		memsetmin(book);
		Goup(i, 1, n)
		{
			scanf("%s", s[i] + 1);
		}
		Goup(i, 1, n)
		{
			Goup(j, 1, m)
			{
				if (s[i][j] == '1')
				{
					sx = i, sy = j;
					len = 1;
					snake = 0;
					init(i, j);
				}
			}
		}
		ans = 0;
		book[sx][sy][snake] = 1;
		cout << bfs(sx, sy, snake) << endl;
	}
	return 0;
}