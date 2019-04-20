#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[4],b[24];
    int f=0;
    while(scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]),a[0]+a[1]+a[2]+a[3]){
        if(f)
        printf("\n");
        f=1;
        memset(b,0,sizeof(b));
        sort(a,a+4);
        int i=0;
        do{
            b[i++]=a[0]*1000+a[1]*100+a[2]*10+a[3];
        }while(next_permutation(a,a+4));
        int s=1;
        sort(b,b+24);
        int flag=0;
        for(int i=0;i<24;i++){
            if(b[i]>=1000)
                if(b[i]/1000==s){
                    if(!flag){
                        printf("%d",b[i]);
                        flag=1;
                    }
                    else {printf(" ");printf("%d",b[i]);}
                }
                else {printf("\n");printf("%d",b[i]); s=b[i]/1000;}
        }
        printf("\n");
    }
	return 0;
}
