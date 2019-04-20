#include<stdio.h>
int main(){
    int x[2],h[2],m[2],s[2],gap,n;
    while(~scanf("%d",&n)){
        int i;
        while(n--){
            gap=0;
            for(i=0;i<2;i++)
                scanf("%dday%d:%d:%d",&x[i],&h[i],&m[i],&s[i]);
            if(s[1]>=s[0])gap+=s[1]-s[0];
            else {s[1]+=60;m[1]-=1;gap+=s[1]-s[0];}
            if(m[1]>=m[0])gap+=(m[1]-m[0])*60;
            else{m[1]+=60;h[1]-=1;gap+=(m[1]-m[0])*60;}
            if(h[1]>=h[0])gap+=(h[1]-h[0])*3600;
            else {h[1]+=24;x[1]-=1;gap+=(h[1]-h[0])*3600;}
            gap+=(x[1]-x[0])*86400;
            printf("%d\n",gap);
        }
    }
    return 0;
}
