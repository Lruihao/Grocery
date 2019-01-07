#include<stdio.h>
int main(){
	int n,j,k,l;
	float a;
	while(scanf("%d",&n)!=EOF&&n!=0){
		j=k=l=0;
		while(n--){
			scanf("%f",&a);
			if(a<0)j++;
			if(a==0)k++;
			if(a>0)l++;
		}
		printf("%d %d %d\n",j,k,l);
	}
	return 0;
}