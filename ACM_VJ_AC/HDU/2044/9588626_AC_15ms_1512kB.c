#include<stdio.h>
int main(){
	int i,n,c,b;
	unsigned long long a[50]={0,1,2};
	for(i=3;i<50;i++)
		a[i]=a[i-2]+a[i-1];
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&c,&b);
		c=b-c;
		printf("%lld\n",a[c]);
	}
	return 0;

}