#include<stdio.h>
#include<string.h>
int a[10010];
int main()
{
    int N;
    int m,i;
    for(i=1;i<=10010;i++)
    {
        a[i]=2*i*i-i+1;
    }
    scanf("%d",&N);
    while(N--)
    {
        int m;
        scanf("%d",&m);
        printf("%d\n",a[m]);

    }
    return 0;
}

 