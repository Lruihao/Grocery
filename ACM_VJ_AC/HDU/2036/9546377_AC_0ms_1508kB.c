#include<stdio.h>
int main(){
    int n,i,x1,y1,x2,y2;
    double s;
    while(scanf("%d",&n),n){
        s=0;
        scanf("%d%d",&x1,&y1);
        int c=x1,d=y1;
        for(i=0;i<n-1;i++){
            scanf("%d%d",&x2,&y2);
            s+=x1*y2-x2*y1;
            if(i+1==n-1)s+=x2*d-c*y2;
            x1=x2;y1=y2;
        }
        printf("%0.1f\n",s/2.0);
    }
    return 0;

}