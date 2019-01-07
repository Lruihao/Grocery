#include<stdio.h>
int main()
{
	int A,B,c,i;
	while((scanf("%d%d",&A,&B)!=EOF)&&(A||B))
	{
		c=A;
		for(i=0;i<B-1;i++)
		{
			c=c%1000;
			c*=A;
		}
		printf("%d\n",c%1000);
	}
	return 0;
}
 
 
