#include<stdio.h>

int main(){
    int t;
    int a[3],b[3];
    scanf("%d",&t);
    while(t){
        int s1=0,s2=0;
        scanf("%d %d %d",&a[0],&a[1],&a[2]);
        scanf("%d %d %d",&b[0],&b[1],&b[2]);
        for(int i=2,j=1;i>=0;i--){
            s1+=a[i]*j;
            s2+=b[i]*j;
            j*=10;
        }
        if(s1==s2)printf("Same\n");
        else if(s1>s2)printf("First\n");
        else printf("Second\n");
        t--;
    }
	return 0;
}
