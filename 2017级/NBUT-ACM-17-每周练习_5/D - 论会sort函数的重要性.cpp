#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int a[50000];

int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
 } 
 
 //  �Լ�ѧϰһ�������sort�Ӵ�С��    
