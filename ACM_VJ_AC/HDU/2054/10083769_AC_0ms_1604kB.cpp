#include<stdio.h>
#include<string.h>
void qu0(char *a)
{
	int len,i;
	len=strlen(a)-1;
	for(i=len;i>=0;i--)
	{
		if(a[i]=='0')      
			len--;                      
		else
			break;
	}
	if(a[len]=='.')    
		len--;
	a[len+1]='\0';    
}

int main()
{
	int i,len;
	char a[50000],b[50000];
	while(~scanf("%s%s",a,b))
	{
		getchar();
		len=strlen(a);
		for(i=0;i<len;i++)
		{
			if(a[i]=='.')   
				qu0(a);
			
			
		}
		len=strlen(b);
		for(i=0;i<len;i++)
		{
			if(b[i]=='.')
				qu0(b);
			
		}
		if(strcmp(a,b))
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}