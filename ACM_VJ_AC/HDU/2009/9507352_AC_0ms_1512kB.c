#include<stdio.h>
#include<math.h>
int main(){
	int n,m,i;
	double s,a;
	while(scanf("%d%d",&n,&m)!=EOF){
		s=n;
		a=sqrt(n);
		for(i=1;i<m;i++){
			s+=a;
			a=sqrt(a);
		}
		printf("%.2lf\n",s);
	}
	return 0;
}