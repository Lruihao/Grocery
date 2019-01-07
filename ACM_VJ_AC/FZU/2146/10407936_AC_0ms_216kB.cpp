#include<stdio.h>
#include<string.h>
int main(){
	char a[10086];
	int t,l,cout=1;
	scanf("%d",&t);
	while(t--){
		scanf("%s",a);
		l=strlen(a);
		if(l%2==0)
			printf("Case %d: Even\n",cout++);
		else printf("Case %d: Odd\n",cout++);
	}
	return 0;
}