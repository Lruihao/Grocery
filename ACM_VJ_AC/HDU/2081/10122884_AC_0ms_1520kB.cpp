#include<stdio.h>
int main(){
	char a[11];
	int n;
	scanf("%d",&n);
	getchar();
	while(n--){
		gets(a);
		printf("6%s\n",a+6);
	}
	return 0;
}