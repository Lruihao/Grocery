#include<stdio.h>
int main(){
	int a[100][100],j,i,c,n;
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<=i;j++)
				scanf("%d",&a[i][j]);
		for(i=n-2;i>=0;i--)
			for(j=0;j<=i;j++){
				if(a[i+1][j]>a[i+1][j+1])
					a[i][j]+=a[i+1][j];
				else a[i][j]+=a[i+1][j+1];
			}
			printf("%d\n",a[0][0]);
	}
	return 0;
}