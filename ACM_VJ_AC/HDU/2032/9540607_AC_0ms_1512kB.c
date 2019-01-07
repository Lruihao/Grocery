#include<stdio.h>
int main(){
    int i,j,a[30][30],n;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            for(j=0;j<=i;j++){
                if(j==0||j==i) a[i][j]=1;
                else a[i][j]=a[i-1][j-1]+a[i-1][j];
                printf("%d",a[i][j]);
                if(j!=i)printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}