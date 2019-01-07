#include<stdio.h>
int have(int a){
	int s;
	if(a==0)s=3;
	else s=(have(a-1)-1)*2;
	return s;
}

int main(){
	int n,a,i;
	scanf("%d",&n);
		for( i=0;i<n;i++){
			scanf("%d",&a);
			printf("%d\n",have(a));
		}
	return 0;
}