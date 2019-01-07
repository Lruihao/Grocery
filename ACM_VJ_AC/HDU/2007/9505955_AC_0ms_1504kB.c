#include<stdio.h>
int main(){
	int x,y,m,n,i,t;
	while(scanf("%d%d",&m,&n)!=EOF){
		x=y=0;
		if(m>n){t=m;m=n;n=t;}
		for(i=m;i<=n;i++){
			if(i%2==0)x+=i*i;
			else y+=i*i*i;
		}
		printf("%d %d\n",x,y);
	}
	return 0;
}