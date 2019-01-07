#include<stdio.h>
int main (){	
	int n,a[100],i,j,t,m,k;	
	while(scanf("%d",&n)!=EOF&&n){		
		for(i=0;i<n;i++)			
			scanf("%d",&a[i]);		
		for(i=0;i<n;i++){	
			if(a[i]<0)m=-a[i];
			else m=a[i];
			for(j=i+1;j<n;j++){
				if(a[j]<0)k=-a[j];
				else k=a[j];
				if(m<k){
					t=a[i];a[i]=a[j];a[j]=t;
					t=m;m=k;k=t;
				}
			}
		}
		for(i=0;i<n-1;i++)		
			printf("%d ",a[i]);		
		printf("%d\n",a[i]);
	}	
	return 0;
}
