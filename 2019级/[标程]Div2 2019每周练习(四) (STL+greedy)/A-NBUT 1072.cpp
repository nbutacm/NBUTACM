#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	
	char str[5000];
	int i;
	
	while (scanf("%s", str) != EOF)
	{
		for (i = 0; i < strlen(str); )
		{
			printf("%s~\n", str + i);
			if (isalpha(str[i]) || isdigit(str[i])) 
				i++;
			else
				i += 2;	
		}
	}
	
	return 0;
}
