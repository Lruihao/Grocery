#include<stdio.h>
int main(){
	int n,i,j,m,k,g=0;
	char a[40][79],c,b,d;
	while(scanf("%d",&n)!=EOF){
		getchar();
		m=n/2+1;
		scanf("%c %c",&b,&c);
		if(n==1){
			if(g!=0)printf("\n");g++;
			printf("%c\n",b);continue;
		}
		if((n+1)%4==0){d=b;b=c;c=d;}
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				a[i][j]=b;
		a[0][0]=a[0][n-1]=' ';
		k=1;
		for(i=1;i<m;i+=2,k+=2)
			for(j=k;j<n-k;j++)
				a[i][j]=c;
		for(k=1;k<m;k+=2)
			for(i=k;i<m;i++)
				a[i][k]=a[i][n-1-k]=c;
		if(g!=0)printf("\n");g++;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++)
				printf("%c",a[i][j]);
			printf("\n");
		}
		for(i=i-2;i>=0;i--){
			for(j=0;j<n;j++)
				printf("%c",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}