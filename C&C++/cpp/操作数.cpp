#include<stdio.h>
int main(){
    int a[100000];
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(k--){
        for(i=1;i<n;i++)
            for(j=0;j<i;j++){
                a[i]+=a[j];
                if(a[i]>=1000000007)
                    a[i]%=1000000007;
            }
    }
    for(i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d",a[i]);
    return 0;
}
