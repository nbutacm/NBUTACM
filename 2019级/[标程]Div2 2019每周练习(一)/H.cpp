#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1){
				for(int i=1;i<=n;i++)
					printf("%3d",i);
			}
			else if(i==n){
				for(int i=1;i<=n;i++)
					printf("%3d",3*n-1-i);
			}
			else{
				printf("%3d",4*n-2-i);
				for(int i=2;i<=n-1;i++)
					printf("   ");
				printf("%3d",n-1+i);
			}
			printf("\n");
		}
	}
	
}
