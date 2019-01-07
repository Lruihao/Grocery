#include<stdio.h>
#define max 20
int main()
{
	int t,n,i;
	int dp2[max]={2};
	int dp1[max]={1}; 
	int dp3[max]={2};

	for(i=1;i<max;i++)
	{
		dp2[i]=3*dp2[i-1]+2; 
	}
	for(i=1;i<max;i++)
	{
		dp1[i]=dp2[i-1]+1+dp1[i-1];
	}
	for(i=1;i<max;i++)
	{
		dp3[i]=2*dp1[i-1]+2;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",dp3[n-1]);
	}
	return 0;
}
 
