#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define ll long long
const ll MAXN=1e6+5;

ll n;
ll a[MAXN];

int main(){
	scanf("%lld",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	
	ll flag=n;       //flag ��ʾ λ����flag������˶����� 
	ll ans=0;        //��ʾ�������� 
	
	for(int i=n-1;i>=0;i--){      //������ǰ�� 
		if(i<flag){               //�����i������flagǰ�棬˵����û�б��������ɱ���������� 
			ans++;
		}
		ll temp=i-a[i];           //�жϵ�i���˿�����ǰɱ���ڼ����� 
		flag=min(flag,temp);      //�����i���˿���ɱ�ñ�flag��ǰ�棬����flag=temp�� 
	}
	printf("%lld",ans);
}

