#include<stdio.h>
#include<string.h>
#define max 50

void turn(int n,int m,char s[]){
	int i,d[max];
	int l,x=0;
	l=strlen(s);
    for(i=0;i<l;i++)
        x=x*n+s[i]-'0';
	i=0;
	while(x){
		d[i++]=x%m;
		x=x/m;
	}
	for(i--;i>=0;i--)
		printf("%d",d[i]);
	printf("\n");
}

int main(){
    int n,m;
    char s[max];
	printf("n->m\n");
	scanf("%d%d",&n,&m);
	getchar();
    scanf("%s",s);
	turn(n,m,s);
    return 0;
}
