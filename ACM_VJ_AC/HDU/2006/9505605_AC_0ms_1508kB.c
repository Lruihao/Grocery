#include<stdio.h>
int main(){
	int i,n,a,s;
	while(scanf("%d",&n)!=EOF){
	s=1;
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(a%2!=0)s=s*a;
	}
	printf("%d\n",s);
	}
	return 0;
}