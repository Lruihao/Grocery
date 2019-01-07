#include <stdio.h>   
#include<math.h>
int main()  
{  
	int x,y,s,t,i,j,flag;
	while(scanf("%d%d",&x,&y)!=EOF){
		if(x==y)if(x==0)break;
		flag=0;
		if(x>y){t=x;x=y;y=t;}
		for(i=x;i<y;i++){
			s=i*i+i+41;
			for(j=2;j<sqrt(s);j++)
				if(s%j==0){printf("Sorry\n");flag=1;break;}
			if(flag)break;
		}
		if(!flag)printf("OK\n");
	}
	return 0;
}  
