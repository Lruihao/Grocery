#include<stdio.h>
int main()
{
    __int64 n,i,a[35]={2};
	for(i=1;i<35;i++)
		a[i]=3*a[i-1]+2;
	while(scanf("%I64d",&n)!=EOF)
		printf("%I64d\n",a[n-1]);
    return 0;
} 
