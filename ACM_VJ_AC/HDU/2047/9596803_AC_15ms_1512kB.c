#include<stdio.h>
int main(){
	int i,n;
	unsigned long long a[40]={3,8};
	for(i=2;i<40;i++)
		a[i]=a[i-1]*2+a[i-2]*2;
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",a[n-1]);
	}
	return 0;

}