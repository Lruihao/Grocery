#include<stdio.h>
#include<math.h>
int main()
{
	int N,M,n,m;
	while(scanf("%d%d",&N,&M),N||M)
	{
		n=(int)sqrt((double)(M)*2);
		while(n)
		{
			m=M/n-(n-1)/2;
			if(m*n+(n*(n-1)/2)==M)
				printf("[%d,%d]\n",m,m+n-1);
			n--;
		}
		printf("\n");
	}
	return 0;
} 