#include<stdio.h>
#include<math.h>
int main(){
    int a,b,c,l;
    scanf("%d%d%d",&a,&b,&c);
    l=a*c/b+b*c/a+a*b/c+2*(a+b+c);
    l=sqrt(l);
    printf("%d\n",4*l);
    return 0;
}
