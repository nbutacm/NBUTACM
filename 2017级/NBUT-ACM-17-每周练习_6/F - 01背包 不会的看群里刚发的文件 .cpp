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
        	//�����Wmax��ʼ����֤ÿ����Ʒֻ�ܷ�1�Σ���ȫ������w[i]��ʼ����֤ÿ����Ʒ���ԷŶ�Σ�
            dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
        }
    }
    cout<<dp[Wmax]<<endl;
    return 0;
}


// ʹ�ö�ά�����ͬѧ�����Ż���һά�����ֹ�Ժ�������ڴ泬��
 
// ���� 01����,������ȫ����,���ر���,���鱳���ȵ� 



