#include<stdio.h>
int main(){
	int a[100],i,j,n,t;
	while(scanf("%d",&n)!=EOF&&n){
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		t=0;
		for(j=1;j<n;j++){
			if(a[t]>a[j])t=j;
		}
		i=a[0];a[0]=a[t];a[t]=i;
		for(i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[i]);
	}
	return 0;
}