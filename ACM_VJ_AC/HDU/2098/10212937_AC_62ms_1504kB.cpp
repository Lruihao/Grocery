#include<stdio.h>
#include<math.h>
int inv(int n)
{
    int i,t=1;
    
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            t=0;
            break;
        }
    }
    return t;
}
int main()
{
    int n,i=3,t=0,sum=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        for(i=3;i<n/2;i=i+2)
        {
            if(inv(i)==1 && inv(n-i)==1)sum++;
        }
        
        printf("%d\n",sum);
        sum=0;
    }
    
    return 0;
}