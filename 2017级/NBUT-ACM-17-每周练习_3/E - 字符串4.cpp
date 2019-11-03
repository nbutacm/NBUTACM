#include<stdio.h>
#include<string.h>

int main() {
	char a[1000000+5];
	int i ,n;
	
	while (scanf("%s", &a)!=EOF)
	{
		 n = strlen(a);
		for (i = 0; i < n; i = i + 2)
		{
			printf("%c%c", a[i + 1], a[i]);
		}
		printf("\n");
	}
	return 0;
}
