#include <stdio.h>

int callatz(int n)
{
  int s = 0;
  while (n != 1) 
  {
    if (n % 2 == 0)
    {
      n = n / 2;
    }
    else
    {
		s++;
		printf(s == 1 ? "%d": " %d", n);
      	n = (3 * n + 1) / 2;
    }
  }
  
  return s;
}

int main(void)
{
  int a, n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
	  scanf("%d", &a);
	  if (0 == callatz(a))
		  printf("No number can be output !");
	  printf("\n");
  }
  
  return 0;
}


