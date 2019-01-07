#include<stdio.h>
#include<string.h>
int main(){
	int i,j,n,m,flag;
	char a[100];
	while(scanf("%d",&n)!=EOF){
		getchar();
		for(i=0;i<n;i++){
			flag=0;
			gets(a);
			m=strlen(a);
			for(j=0;j<m/2;j++)
				if(a[j]!=a[m-1-j]){flag=1;break;}
			if(flag)printf("no\n");
			else printf("yes\n");
		}
	}
	return 0;
}