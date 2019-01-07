#include<stdio.h>
int main()
{
    __int64 a[51]={0,1,1},i,n;
	for(i=3;i<51;i++)
		a[i]=a[i-1]+a[i-2];
    while(scanf("%I64d",&n)!=EOF,n!=-1){
          printf("%I64d\n",a[n]);  
    }
    return 0;
} 
