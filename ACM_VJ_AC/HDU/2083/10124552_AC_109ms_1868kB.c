#include<stdio.h>
#include<math.h>
int main(){
	int n,m,i=0,j,t,sum,a[10000];
	scanf("%d",&m);
	while(m--){
		sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(a[i]>a[j]){t=a[i];a[i]=a[j];a[j]=t;}
		t=a[n/2];
		for(i=0;i<n;i++)
			sum=sum+abs(a[i]-t);
		printf("%d\n",sum);
	}
	return 0;
}