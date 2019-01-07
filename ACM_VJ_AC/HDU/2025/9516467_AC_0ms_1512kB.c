#include<stdio.h>
int main(){
	char a[100],t;
	int j,i;
	while(scanf("%s",a)!=EOF){
		getchar();
		t=a[0];
		for(j=1,i=0;a[j]!='\0';j++)
			if(a[i]<a[j]){t=a[j];i=j;}
		for(i=0;a[i]!='\0';i++){
			printf("%c",a[i]);
			if(a[i]==t)printf("(max)");
		}
		printf("\n");
	}
	return 0;
}