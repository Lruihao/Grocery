#include<stdio.h>

int main(){
    int x,y,z;
    for(x=0;x<=20;x++) //21*34=714
    for(y=0;y<=33;y++){
        z=100-y-x;
        if(z%3==0 && (5*x+3*y+z/3)==100){//限定z能被3整除，进一步提高效率
            printf("cock number:%d\t",x);
            printf("hen number:%d\t",y);
            printf("chick number:%d\n",z);
        }
    }
	return 0;
}
