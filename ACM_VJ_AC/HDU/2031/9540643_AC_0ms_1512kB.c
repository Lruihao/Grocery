#include<stdio.h>
int main(){
    int a,b,c,i,m,d[100],r;
    while(scanf("%d%d",&a,&r)!=EOF){
        if(a<0){a=-a;printf("-");}
        m=0;
        i=0;
        b=a%r;
        d[0]=b;
        m++;
        c=a/r;
        while(c!=0){
            a=c;
            c=a/r;
            b=a%r;
            d[++i]=b;
            m++;
        }
        for(i=m-1;i>=0;i--){
            if(d[i]==10)printf("A");
            if(d[i]==11)printf("B");
            if(d[i]==12)printf("C");
            if(d[i]==13)printf("D");
            if(d[i]==14)printf("E");
            if(d[i]==15)printf("F");
            if(d[i]<10)printf("%d",d[i]);
        }
        printf("\n");
    }
    return 0;
}