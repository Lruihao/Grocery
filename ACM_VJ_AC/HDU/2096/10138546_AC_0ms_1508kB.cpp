#include<stdio.h>
int main(){
	int k,t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		a=a%100;
		b=b%100;
		k=(a+b)%100;
		printf("%d\n",k);
	}
	return 0;
}