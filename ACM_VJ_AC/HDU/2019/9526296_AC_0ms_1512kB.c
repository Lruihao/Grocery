#include<stdio.h>
int main(){
	int n,m,i,a[100],j;
	while(scanf("%d%d",&n,&m)){
		if(n==0)if(m==0)break;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			if(a[i]<m)printf("%d ",a[i]);
			else break;
		if(n==i)printf("%d",m);
		else printf("%d ",m);
		for(i;i<n;i++){
			printf("%d",a[i]);
			if(i!=n-1)printf(" ");
			}
		printf("\n");
	}
	return 0;
}