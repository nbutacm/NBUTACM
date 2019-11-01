#include <stdio.h>
#include <string.h>

char a[1000];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			int i,len,z=0;
			scanf("%s",a);
			len = strlen(a);
			
			for(i=0;i<len;i++)
			{
				if(a[i]>='0'&&a[i]<='9')
				{
					z++;
				}
			}
			
			printf("%d\n",z);
		}
	}
	
	return 0;
}
