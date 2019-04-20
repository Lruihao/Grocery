#include<iostream.h>
const int MAX=1001;
int a[MAX];
int lis(int x)
{
    int sum[MAX],i,j;
    for(i=0;i<x;i++){
        sum[i]=1;
        for(j=0;j<i;j++)
            if(a[j]<a[i]&&sum[j]+1>sum[i])
                sum[i]=sum[j]+1;
    }
    int max=0;
    for(i=0;i<x;i++)
        if(sum[i]>max)
            max=sum[i];
    return max;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<lis(n)<<endl;
    return 0;
}
