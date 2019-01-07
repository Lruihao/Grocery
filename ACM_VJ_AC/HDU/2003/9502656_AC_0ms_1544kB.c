#include<stdio.h>
int main(){
	double v;
	while(scanf("%lf",&v)!=EOF){
		if(v<0)v=-v;
	printf("%.2lf",v);
	printf("\n");
	}
	return 0;
}