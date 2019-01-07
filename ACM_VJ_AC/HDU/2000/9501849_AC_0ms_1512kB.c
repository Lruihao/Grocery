#include<stdio.h>
int main(){
	char a[3],t;
	int i,j;
	while(scanf("%c%c%c",&a[0],&a[1],&a[2])!=EOF){
		getchar();
		for(i=0;i<3;i++)
			for(j=i+1;j<3;j++)
				if(a[i]>a[j]){
				t=a[i];a[i]=a[j];a[j]=t;
				}
		printf("%c %c %c",a[0],a[1],a[2]);
	printf("\n");
	}
	return 0;
}