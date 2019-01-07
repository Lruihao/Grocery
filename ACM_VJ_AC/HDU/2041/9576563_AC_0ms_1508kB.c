#include<stdio.h>
int main()
{
    int a,i,t;
    int feibo[50]={1,1};
    for(i=2;i<=40;i++)
    {
        feibo[i]=feibo[i-1]+feibo[i-2];
    }
   while(~scanf("%d",&t))
   {
       while(t--)
       {
           scanf("%d",&a);
           printf("%d\n",feibo[a-1]);
       }
   }
   return 0;
}
