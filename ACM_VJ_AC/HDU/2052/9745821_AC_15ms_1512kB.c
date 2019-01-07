#include<stdio.h>
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		printf("+");
		int i,j;
		for(i=0;i<a;i++)
			printf("-");
		printf("+\n");
		for(i=0;i<b;i++)
		{
			printf("|");
			for(j=0;j<a;j++)
				printf(" ");
			printf("|\n");
		}
		printf("+");
		for(i=0;i<a;i++)
			printf("-");
		printf("+\n");
		printf("\n");
	}
	return 0;
}