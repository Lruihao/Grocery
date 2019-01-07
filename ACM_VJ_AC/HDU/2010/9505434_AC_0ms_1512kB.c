#include<stdio.h>
int main(){
	int m,n,i,a,b,c,k;
	while(scanf("%d%d",&m,&n)!=EOF){
		k=0;
		for(i=m;i<=n;i++){
			a=i/100;b=i/10%10;c=i%10;
			if(i==a*a*a+b*b*b+c*c*c&&k==0)
			{printf("%d",i);k++;}
			else if(i==a*a*a+b*b*b+c*c*c&&k!=0)
			{printf(" %d",i);k++;}
		}
		if(!k)printf("no");
		printf("\n");
	}
	return 0;
}
