#include<stdio.h>
#include<math.h>
int main(){
	float x1,x2,y1,y2,l,x,y;
	while(scanf("%f%f%f%f",&x1,&y1,&x2,&y2)!=EOF){
	x=x1-x2;
	y=y1-y2;
	l=sqrt(x*x+y*y);
	printf("%.2f",l);
	printf("\n");
	}
	return 0;
}