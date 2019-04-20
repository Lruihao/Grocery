#include<cstdio>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int MAXN=500100;
int d[MAXN];
int c[20];
int main()
{
    while(1){
    memset(d,0,sizeof(d));
    int n,i,j;
    c[0]=1;
    for(int i=0;i<20;i++)
    {
        c[i+1]=2<<i;
    }
    scanf("%d",&n);
    int p=upper_bound(c,c+20,n-1)-c;
    if(p!=0)p--;
    for(int i=n-1;i>=0;i--)
    {
        if(i!=0&&d[i]==0)
        {
            while(i<c[p])p--;
            d[i]=2*c[p]-i-1;
            d[2*c[p]-i-1]=i;
        }
    }
    for(int i=0;i<n-1;i++)
        printf("%d ",d[i]);
    printf("%d\n\n",d[n-1]);
    }
    return 0;
}
