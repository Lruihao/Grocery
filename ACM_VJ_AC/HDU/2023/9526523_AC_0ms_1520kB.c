#include <stdio.h>
int main()
{
	int m,n,i,j,x,f;
	int s[50][5];
	double sum,aver[5];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&s[i][j]);
		for(i=0;i<n;i++)
		{
			for(sum=j=0;j<m;j++)
			{
				sum+=s[i][j];
			}
			printf("%.2lf",sum*1.0/m);
			if(i!=n-1)
				printf(" ");
		}
		printf("\n");

		for(j=0;j<m;j++)
		{
			for(sum=i=0;i<n;i++)
			{
				sum+=s[i][j];
			}
			aver[j]=sum/n*1.0;
			printf("%.2lf",aver[j]);
			if(j!=m-1)
				printf(" ");
		}
		printf("\n");

		for(x=i=0;i<n;i++)
		{
			for(f=j=0;j<m;j++)
			{
				if(s[i][j]<aver[j])
				{
					f=1;
					break;
				}
			}
			if(!f)
				x++;
		}
		printf("%d\n\n",x);
	}
	return 0;
}
