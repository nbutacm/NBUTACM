#include <iostream>  
#include <algorithm>  
#include <queue>  
#include <string.h>  
using namespace std;  
  
char map[202][202];//��ͼ
int vis[202][202];  //����Ƿ��߹� 
int ans[202][202];  //������ٲ��� 
int flag[202][202]; //��Ǳ��������߹�
int dx[4]={0,0,-1,1};  
int dy[4]={1,-1,0,0};//����  
int n,m;//��ͼ��С  
int yx,yy,mx,my;//Y�����꣬M������  

struct node{  
    int x,y,setp;  
};  
  
void bfs(int x,int y)//����  
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
            	if(map[i][j]=='@'&&flag[i][j]==2){//���뱣֤�˴�@�������˷��ʹ���
                	minn=min(minn,ans[i][j]);//ĳ��KFC�ص����ߵ�����ܲ���֮�ͣ�ȡ��Сֵ��  
            	}  
        	}  
        }
        cout<<minn*11<<endl;  
    }  
    return 0;  
}  
