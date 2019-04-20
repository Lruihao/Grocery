#include<stdio.h>
int main(){
    int T,n,m,d[30000],c[30000],t;
    scanf("%d",&T);
    while(T--){
        int i,j,s;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d %d",&d[i],&c[i]);
        for(i=0;i<m;i++){
            scanf("%d",&t);
            for(j=0;j<n;j++)
                if(t>=d[j]&&c[j]>s)s=c[j];
            printf("%d\n",s);
        }
    }
    return 0;
}
