#include <queue>
#include <cstdio>
#include <cstring> 
#include <iostream>
using namespace std;
struct node {
    int x, y, t, st;
    node( int X, int Y, int T, int S ) {
        x = X, y = Y, t = T, st = S;
    }
};
queue < node > q;
int n, m, len, sx, sy;
int dir[16], dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
int chess[16][16];
bool vis[16][16][65600];
 
int Hash() {
    int sum = 0;
    for( int i = 1;i < len;i ++ )
        sum *= 4, sum += dir[i];
    return sum;
}
 
int move( int x, int y ) {
    int ppp = dir[len - 1];
    for( int i = len - 1;i > 1;i -- )
        dir[i] = dir[i - 1];
    if( x == -1 ) dir[1] = 1;
    if( x == 1 ) dir[1] = 0;
    if( y == -1 ) dir[1] = 3;
    if( y == 1 ) dir[1] = 2; 
    int temp = Hash();
    for( int i = 1;i < len - 1;i ++ )
        dir[i] = dir[i + 1];
    dir[len - 1] = ppp;
    return temp;
}
 
void re_hash( int st ) {
    memset( dir, 0, sizeof( dir ) );
    int ip = len;
    while( st ) dir[-- ip] = st % 4, st /= 4;
}
 
bool check( int x, int y, int tx, int ty ) {
    for( int i = 1;i < len;i ++ ) {
        if( dir[i] == 0 ) x --;
        if( dir[i] == 1 ) x ++;
        if( dir[i] == 2 ) y --;
        if( dir[i] == 3 ) y ++;
        if( x == tx && y == ty ) return 1;
    }
    return 0;
}
 
void bfs() {
    int temp = Hash(); 
    q.push( node( sx, sy, 0, temp ) );
    vis[sx][sy][temp] = 1;
    while( ! q.empty() ) {
        node t = q.front(); q.pop();
        re_hash( t.st );
        for( int i = 0;i < 4;i ++ ) {
            int tx = t.x + dx[i], ty = t.y + dy[i];
            if( tx < 1 || ty < 1 || tx > n || ty > m ) continue;
            if( chess[tx][ty] == -1 ) continue;
            if( check( t.x, t.y, tx, ty ) ) continue;
            int temp = move( dx[i], dy[i] );
            if( vis[tx][ty][temp] ) continue;
            if( chess[tx][ty] == -2 ) {
                printf( "%d", t.t + 1 );
                exit( 0 );
            }
            vis[tx][ty][temp] = 1;
            q.push( node( tx, ty, t.t + 1, temp ) );
        }
    }
    printf( "-1" );
}
//ио0об1вС2ср3 
int main() {
    scanf( "%d %d", &n, &m );
    for( int i = 1;i <= n;i ++ ) {
        scanf( "\n" );
        for( int j = 1;j <= m;j ++ ) {
            char ch;
            scanf( "%c", &ch );
            if( ch == '#' ) chess[i][j] = -1;
            else if( ch == '.' ) chess[i][j] = 0;
            else if( ch == '@' ) chess[i][j] = -2;
            else {
                chess[i][j] = ch - '0';
                if( chess[i][j] == 1 ) sx = i, sy = j;
            }
        }
    }
    int x = sx, y = sy;
    while( 1 ) {
        if( chess[x + 1][y] == chess[x][y] + 1 )
            dir[++ len] = 1, x ++;
        else if( chess[x - 1][y] == chess[x][y] + 1 )
            dir[++ len] = 0, x --;
        else if( chess[x][y + 1] == chess[x][y] + 1 )
            dir[++ len] = 3, y ++;
        else if( chess[x][y - 1] == chess[x][y] + 1 )
            dir[++ len] = 2, y --;
        else break;
    }
    bfs();
    return 0;
}
