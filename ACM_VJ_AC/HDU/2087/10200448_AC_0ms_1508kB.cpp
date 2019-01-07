#include<stdio.h>
#include<string.h>
int main(){
	int i,j;
	char a[1000],b[1000];
	while(scanf("%s",a),a[0]!='#'){
		scanf("%s",b);
		int la=strlen(a),lb=strlen(b),cout=0;
		for(i=0,j=0;i<la;i++){
			if(a[i]==b[j])j++;
			else j=0;
			if(j==lb){j=0;cout++;}
		}
		printf("%d\n",cout);
	}
	return 0;
}