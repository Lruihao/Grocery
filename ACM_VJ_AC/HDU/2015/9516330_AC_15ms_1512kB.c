#include<stdio.h>
int main() {
  int sum=0,cout=0,flag=0,n,m,x,i;
  while(scanf("%d %d",&n,&m)!=EOF){
  	for(i=1;i<=n;i++){
  		x=2*i;
  		sum+=x;
  		cout++;
  		if(cout==m){
  			printf("%d",sum/m); 
  			sum=cout=0;
  			flag=0;
  			if((n-i)!=0){printf(" ");flag=1;}
  		}
  	}
  	if(flag==1){
  	   printf("%d",sum/cout);
  	   sum=cout=0;
  	}
  	flag=0;
  	printf("\n");
  }
  return 0;
}