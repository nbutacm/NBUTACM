#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm> 
using namespace std;
typedef long long ll;
int main(){
	int m;
	int a[1005];
	while(~scanf("%d",&m)){
		for(int i=0;i<m;i++) scanf("%d",&a[i]);
		bool flag=false;
		sort(a,a+m);
		for(int i=0;i<m;i++){
			int j=i+1,k=m-1;
			int cnt=-a[i];
			while(j<k){
				int pns=a[j]+a[k];
				if(pns==cnt){
					printf("%d %d %d\n",a[i],a[j],a[k]);
					j++;k--;
					flag=true;
				}
				else if(pns>cnt) k--;
				else j++;
			}
		}
		if(!flag) printf("No Solution\n");
	}	
	return 0;	
}

