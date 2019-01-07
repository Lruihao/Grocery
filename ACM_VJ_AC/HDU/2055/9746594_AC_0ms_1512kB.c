#include<stdio.h>
int main(){
	int n,b,d;
	char a;
	scanf("%d",&n);
	while(n--){
		getchar();
		scanf("%c%d",&a,&b);
		d=a-'A'+1;
		if(d>32)d=-(d-32);
		printf("%d\n",d+b);
	}
	return 0;
}