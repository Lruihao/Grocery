#include<stdio.h>
int main()
{
    __int64 a,b;
    while(scanf("%I64X%I64X",&a,&b)==2){
            if(a+b<0)
            printf("-%I64X\n",-(a+b));
            else printf("%I64X\n",(a+b));
            }
    return 0;
} 
