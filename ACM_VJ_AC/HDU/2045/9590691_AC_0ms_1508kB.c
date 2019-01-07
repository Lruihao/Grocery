#include<stdio.h>
int main(){
	int i,n;
        unsigned long long a[50]={3,6,6};
	for(i=3;i<50;i++)
		a[i]=a[i-1]+a[i-2]*2;
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",a[n-1]);
	}
	return 0;

}