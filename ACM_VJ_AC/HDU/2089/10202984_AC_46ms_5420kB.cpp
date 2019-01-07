#include<stdio.h>
int f(int x){
    while(x){
        if(x % 10 == 4) return 1;
        if(x %100 ==62) return 1;
        x /=10;
    }
    
    return 0;
}

int main(){
    int i,sum=0,a[1000000];
    for(i=1 ;i<1000000 ;i++){
        if(f(i)){
            sum++;
        }
        a[i]=sum;
    }
    int m,n,cnt;
    while(scanf("%d%d",&m,&n) != EOF && (m||n)){
        cnt = (n-m+1) - (a[n] - a[m-1]);
        printf("%d\n",cnt);
    }
    return 0;
}

