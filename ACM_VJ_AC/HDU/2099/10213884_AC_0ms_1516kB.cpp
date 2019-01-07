#include<stdio.h>
int main()
{
  int a, b, i, c;
  while (scanf("%d %d", &a, &b)==2 ,a||b)
  {
    a *= 100; c = 0;
    for (i=0; i<=99; ++i)
    {
     if ((a+i)%b == 0)
     {
      if(c) 
        printf(" "); 
      c = 1;
     printf("%02d", i);
    }
    }
   printf("\n");
  }
  return 0;
}