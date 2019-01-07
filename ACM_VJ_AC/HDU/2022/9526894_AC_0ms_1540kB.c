#include<stdio.h> 
#include<math.h>
int main()
{
	int a[100][100];
	int i,j,n,m,f1,f2;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)
		 for(j=1;j<=m;j++)
		 	scanf("%d",&a[i][j]);
		 f1=1;f2=1;

		 for(i=1;i<=n;i++)
		  for(j=1;j<=m;j++)
		  {
		  	if(abs(a[i][j])>abs(a[f1][f2]))
		  	{
		  		f1=i;
		  		f2=j;
			  }
		  }
		  printf("%d %d %d\n",f1,f2,a[f1][f2]); 
	}
	return 0;
}