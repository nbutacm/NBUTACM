#include <iostream>
using namespace std;
int w[10010],p[10010],dp[10010];

int main(){
    int n,Wmax;
    cin>>n>>Wmax;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>p[i];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=Wmax;j>=w[i];j--){
        	//这里从Wmax开始，保证每件物品只能放1次（完全背包从w[i]开始，保证每件物品可以放多次）
            dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
        }
    }
    cout<<dp[Wmax]<<endl;
    return 0;
}


// 使用二维数组的同学尽量优化到一维数组防止以后大数据内存超限
 
// 除了 01背包,还有完全背包,多重背包,分组背包等等 



