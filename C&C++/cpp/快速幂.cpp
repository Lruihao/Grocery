#include<stdio.h>
int main(){
	__int64 a,n,ans=1;
	scanf("%I64d%I64d",&a,&n);
	while(n){
		if(n&1)
			ans*=a;
		a=a*a;
		n=n>>1;
	}
	printf("%I64d\n",ans);
	return 0;
}
