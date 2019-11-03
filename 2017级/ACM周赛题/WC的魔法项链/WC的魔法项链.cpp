//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//
//int n,k;
//int a[200005];
//int ans,temp;
//
//int mn(){
//	//freopen("data.in","r",stdin);
//	//freopen("data.out","w",stdout);
//	while(scanf("%d%d",&n,&k)!=EOF){
//		ans=0;
//		temp=0;
//		for(int i=0;i<n;i++){
//			cin>>a[i];
//			a[i+n]=a[i];
//		}
//		for(int i=0;i<k;i++){
//			temp+=a[i];
//		}
//		ans=temp;
//		for(int i=k;i<2*n;i++){
//			temp=temp+a[i]-a[i-k];
//			ans=max(ans,temp);
//		}
//		printf("%d\n",ans);
//	}
//	return 0;
//}
