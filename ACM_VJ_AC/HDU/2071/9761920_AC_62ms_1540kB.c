#include<stdio.h>
int main()
{
    int t,n;
	double a,max;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%lf",&a);
		max=a;n--;
		while(n--){
			scanf("%lf",&a);
			if(a>max)
			max=a;
		}
		printf("%.2lf\n",max);
	}
    return 0;
} 
