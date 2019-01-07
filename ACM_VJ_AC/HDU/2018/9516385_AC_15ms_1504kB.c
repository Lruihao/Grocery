#include <stdio.h>
int main()
{
	int j,n,a[60]={0,1,2,3,4};
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(j=5;j<=n;j++)
			a[j]=a[j-1]+a[j-3];
		printf("%d\n",a[n]);
	}
	return 0;
}
