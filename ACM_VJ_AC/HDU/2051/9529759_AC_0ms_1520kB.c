#include<stdio.h>
int main(){
	int a,b,c,i,m,d[100];
	while(scanf("%d",&a)!=EOF){
	m=i=0;
	b=a%2;
	d[0]=b;
	m++;
	c=a/2;
	while(c!=0){
		a=c;
		c=a/2;
		b=a%2;
		d[++i]=b;
		m++;
	}
	for(i=m-1;i>=0;i--)
		printf("%d",d[i]);
	printf("\n");
	}
	return 0;
}