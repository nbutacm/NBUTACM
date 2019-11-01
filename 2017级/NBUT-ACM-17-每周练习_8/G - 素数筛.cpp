#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e7 + 5;
bool isprime[N];//isprime[i]表示i是不是质数
int prime[N];//prime[N]用来存质数  从1开始
int tot=1;//tot表示[2，N]之间质数的数量
void init(){
    for(int i = 2; i < N; i ++) isprime[i] = true;//初始化为质数
    for(int i = 2; i < N; i++){
        if(isprime[i]){         //把质数存起来
			prime[tot]=i;
			tot++;
		}
        for(int j = 1; j <= tot && i * prime[j] < N; j++){
            isprime[i * prime[j]] = false;         //质数的倍数一定不是质数
            if(i % prime[j] == 0) break;           //保证每个合数被它最小的质因数筛去
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
