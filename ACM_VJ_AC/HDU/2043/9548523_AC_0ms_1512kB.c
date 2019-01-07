#include<stdio.h>
#include<string.h>
int main(){
	int m,l,i,c,flag;
	char str[50];
	scanf("%d",&m);
	getchar();
	while(m--){
		gets(str);
		l=strlen(str);
		int b[4]={0};
		flag=c=0;
		if(l>=8&&l<=16)
		{	for(i=0;i<l;i++)
			{	if(str[i]>='a'&&str[i]<='z') b[0]=1;
				if(str[i]>='A'&&str[i]<='Z') b[1]=1;
				if(str[i]>='0'&&str[i]<='9') b[2]=1;
				if(str[i]=='~'||str[i]=='!'||str[i]=='@'||str[i]=='$'||str[i]=='%'||str[i]=='^')b[3]=1;
			}
			for(i=0;i<4;i++)
				if(b[i]==1)c++;
			if(c>=3)printf("YES\n");
			else printf("NO\n");
		}
		else
			printf("NO\n");

	}
	return 0;
}