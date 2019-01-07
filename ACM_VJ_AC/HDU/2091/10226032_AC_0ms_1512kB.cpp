#include<stdio.h>
int main(){
	int i,j,n,k=0;
	char a[41][81],b;
	while(scanf("%c",&b),b!='@'){
		scanf("%d",&n);
		getchar();
		for(i=0;i<n-1;i++)
			a[i][n+i-1]=a[i][n-i-1]=b;
		if(k)printf("\n");
		for(i=0;i<n-1;i++){
			for(j=0;j<2*n-1;j++){
				if(j==n+i){printf("\n");break;}
				if(a[i][j]==b) printf("%c",a[i][j]);
				else printf(" ");
			}
		}
		for(i=0;i<2*n-1;i++)
			printf("%c",b);
		printf("\n");
		k=1;
	}
	return 0;	
}