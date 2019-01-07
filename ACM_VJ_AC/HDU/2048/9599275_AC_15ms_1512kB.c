#include<stdio.h>
int main()
{
    int i,n,T;
    double a[21]={0,0,1};
    double b[21]={1,1,2};
    for(i=3;i<=20;++i)
    {
        a[i]=(a[i-1]+a[i-2])*(i-1); 
        b[i]=b[i-1]*i;
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%.2lf%%\n",a[n]/b[n]*100);
    }
    return 0;
}