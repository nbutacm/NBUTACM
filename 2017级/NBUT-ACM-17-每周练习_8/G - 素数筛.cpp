#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e7 + 5;
bool isprime[N];//isprime[i]��ʾi�ǲ�������
int prime[N];//prime[N]����������  ��1��ʼ
int tot=1;//tot��ʾ[2��N]֮������������
void init(){
    for(int i = 2; i < N; i ++) isprime[i] = true;//��ʼ��Ϊ����
    for(int i = 2; i < N; i++){
        if(isprime[i]){         //������������
			prime[tot]=i;
			tot++;
		}
        for(int j = 1; j <= tot && i * prime[j] < N; j++){
            isprime[i * prime[j]] = false;         //�����ı���һ����������
            if(i % prime[j] == 0) break;           //��֤ÿ������������С��������ɸȥ
        }
    }
}
int main(){
	int n;
	cin>>n;
	init();
	for(int i=1;i<=tot;i++){
		if(prime[prime[i]]>=n){
			cout<<prime[prime[i]]<<endl;
			return 0;
		}
	}
}
