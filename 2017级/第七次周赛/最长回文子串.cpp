
/**************************************/
// 最暴力的方法  
//时间复杂度  O(n^3)   最多处理 1000 长度的字符串 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s;
int ans;

int main(){
	cin>>s;
	ans=1;
	for(int i=0;i<s.size();i++){
		for(int j=i;j<s.size();j++){
			int temp=0;
			for(int k=i,l=j;k<=l;k++,l--){
				if(s[k]==s[l]){
					if(k==l) temp+=1;
					else temp+=2;
				}
				else{
					temp=0; 
					break;
				}
			}
			ans=max(ans,temp);
		}
	}
	cout<<ans<<endl;	
} 

/**************************************************/
// 每次从一个字符开始向两边延伸 
////时间复杂度  O(n^2)   最多处理 10000 长度的字符串  
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s;
int ans;

int find1(string s,int n){
	int ans=1;
	int i=1;
	while(n-i>=0&&n+i<s.size()){
		if(s[n-i]==s[n+i]){
			ans+=2;
			i++;
		}
		else return ans;
	}
	return ans;
}

int find2(string s,int n){
	int ans=0;
	int i=0;
	while(n-i>=0&&n+1+i<s.size()){
		if(s[n-i]==s[n+1+i]){
			ans+=2;
			i++;
		}
		else return ans;
	}
	return ans;
}

int main(){
	cin>>s;
	ans=1;
	for(int i=0;i<s.size();i++){
		int t1=0,t2=2;
		t1=find1(s,i);  //奇数的回文串 
		t2=find2(s,i);  //偶数的回文串 
		ans=max(ans,max(t1,t2));
	}
	cout<<ans<<endl;	
}   


/********************************************************/
// 最最厉害的 Manacher算法
//  http://www.cnblogs.com/zyf0163/p/4780174.html?ptvd    算法具体看这个链接 
////时间复杂度  O(nlogn)   可以处理 1000000 长度的字符串
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 220000 + 5;

char s[N];
int p[N];
int n, id, mx;

void work(){
    id = mx = 0;
    int ans = 0;
    n = strlen(s);
    for(int i = n; i >= 0; i --){
        s[2 * i + 2] = s[i];
        s[2 * i + 1] = '#';
    }
    s[0] = '@';
    p[0] = 1;
    for(int i = 1; i < 2 * n + 2; i ++){
        if(mx > i)p[i] = min(p[2 * id - i], mx - i);
        else p[i] = 1;
        while(s[i + p[i]] == s[i - p[i]]) p[i] += 1;
        if(mx < p[i] + i){
            id = i;
            mx = p[i] + i;
        }
        ans = max(ans, p[i] - 1);
    }
    printf("%d\n", ans);
}

int main(){
    while(scanf("%s", s) == 1){
		work();
	} 
    return 0;
}                          
