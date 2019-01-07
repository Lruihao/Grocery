#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(n%i==0)	cnt++;
		if(cnt%2)	printf("1\n");
		else		printf("0\n");
	}
	return 0;
} 
 