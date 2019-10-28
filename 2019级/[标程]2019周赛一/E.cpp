#include <stdio.h>
#include <math.h>
int primer(long long a)
{
	if (a<=1)
		return 0;
	for (int i=2;i * i <= a;i++)
		if (a % i == 0) return 0;
	return 1;
} 
 
int main(void)
{
    long long x,y;
    int n;
    int i;
    scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%lld %lld",&x,&y);
		if((x-y)==1 && primer(x+y))
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}
