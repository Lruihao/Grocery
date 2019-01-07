#include<stdio.h>
int main(){
	int a,b,s,i,n;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			s=0;
			scanf("%d%d",&a,&b);
			for(i=1;i<a;i++)
				if(a%i==0)s+=i;
			if(s!=b){printf("NO\n");continue;}
			s=0;
			for(i=1;i<b;i++)
				if(b%i==0)s+=i;
			if(s==a)printf("YES\n");
		}
	}
	return 0;

}