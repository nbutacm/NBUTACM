#include <iostream>  
#include <algorithm>  
#include <queue>  
#include <string.h>  
using namespace std;  
  
char map[202][202];//地图
int vis[202][202];  //标记是否走过 
int ans[202][202];  //标记最少步数 
int flag[202][202]; //标记被几个人走过
int dx[4]={0,0,-1,1};  
int dy[4]={1,-1,0,0};//方向  
int n,m;//地图大小  
int yx,yy,mx,my;//Y的坐标，M的坐标  

struct node{  
    int x,y,setp;  
};  
  
void bfs(int x,int y)//广搜  
{  
	memset(vis,0,sizeof(vis)); 
    queue<node>q;  
    node aa;  
    aa.x=x;  
    aa.y=y;  
    aa.setp=0;  
    q.push(aa);  
    while(!q.empty())  
    {  
    	node bb;
        bb=q.front();  
        q.pop();  
        for(int i=0;i<4;i++)  
        {  
            int xx=bb.x+dx[i];  
            int yy=bb.y+dy[i];  
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy]==0&&map[xx][yy]!='#')  
            {  
				ans[xx][yy]+=bb.setp+1;
				vis[xx][yy]=1;
				flag[xx][yy]++;
				
				node New;
				New.x=xx;
				New.y=yy;
				New.setp=bb.setp+1;  
                q.push(New);  
                
            }  
        }//for  
    }//while  
}  
int main(){  
    while(cin>>n>>m){ 
        memset(ans,0,sizeof(ans));
        memset(flag,0,sizeof(flag));
        
        for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){  
		        cin>>map[i][j];  
		        if(map[i][j]=='Y'){  
		            yx=i;  
		            yy=j;  
		        }  
		        else if(map[i][j]=='M'){  
		            mx=i;  
		            my=j;  
		        }  
	    	}  
		}  
        
        bfs(yx,yy);  
        bfs(mx,my); 
		 
        int minn=999999999;     
        for(int i=0;i<n;i++){ 
            for(int j=0;j<m;j++){  
            	if(map[i][j]=='@'&&flag[i][j]==2){//必须保证此处@被两个人访问过！
                	minn=min(minn,ans[i][j]);//某个KFC地点两者到达的总步数之和，取最小值。  
            	}  
        	}  
        }
        cout<<minn*11<<endl;  
    }  
    return 0;  
}  
