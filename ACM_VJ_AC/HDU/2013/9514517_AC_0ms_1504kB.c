#include <stdio.h>
int first(int n){
	int a;
	if(n==1)a=1;
	else a=(first(n-1)+1)*2;
	return a;
}

int main()  
{
	int n;
	while(scanf("%d",&n)!=EOF){
	printf("%d\n",first(n));
	}
	return 0;
}  

