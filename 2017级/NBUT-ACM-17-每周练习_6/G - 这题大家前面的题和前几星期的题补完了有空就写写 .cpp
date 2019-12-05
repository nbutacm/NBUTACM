#include <iostream>
#include <string.h>
using namespace std;

int max(int x,int y){
	return x>y?x:y;
}

int len_ans;
char a[1005],b[1005],ans[1005];
int c[1005][1005];

void back(int x,int y){
	if(x==0||y==0){
		return;
	}
	if(a[x-1]==b[y-1]){
		ans[len_ans-1]=a[x-1];
		len_ans--;
		back(x-1,y-1);
		return;
	}
	if(a[x-1]!=b[y-1]){
		if(c[x-1][y]==c[x][y-1]){
			back(x,y-1);
		}
		if(c[x-1][y]>c[x][y-1]){
			back(x-1,y);
		}
		if(c[x-1][y]<c[x][y-1]){
			back(x,y-1);
		} 
	}
	return;
}

int main()
{
	
	/***********************************************/ 
	int i,j;
	cin >> a;
	cin >> b;
	int len_a = strlen(a);
	int len_b = strlen(b);
	for(i=0;i<=max(len_a,len_b);i++){
		c[i][0]=0;
		c[0][i]=0;
	}
	for(i=1;i<=len_a;i++){
		for(j=1;j<=len_b;j++){
			if(a[i-1]==b[j-1]){
				c[i][j]=c[i-1][j-1]+1;
			}
			else{
				c[i][j]=max(c[i-1][j],c[i][j-1]);
			}
		}
	}
	len_ans=c[len_a][len_b];  
	    
	 //c[len_a][len_b] 就是两个字符串的最长公共子序列长度,到这里会了就可以了,下面学有余力的可以看看
	/***********************************************/
	 
	back(len_a,len_b);
	cout << ans << endl;
	return 0;
}
