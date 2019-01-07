#include <stdio.h>
int main()  
{	
	int min,max,s,n,a,i;
	while(scanf("%d",&n)!=EOF){
		max=s=0;
		min=100;
		for(i=0;i<n;i++){
			scanf("%d",&a);
			s+=a;
			if(a>max)max=a;
			if(a<min)min=a;
		}	printf("%.2f\n",(s-min-max)/(n-2+0.0));
	}
	return 0;
}  
