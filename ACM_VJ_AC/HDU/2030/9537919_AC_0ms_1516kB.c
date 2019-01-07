#include <stdio.h>
int main()
{
	int num,n,i;
	char s[10000];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n--)
		{
			gets(s);
			for(num=0,i=0;s[i]!='\0';i++)
				if(s[i]<0)
					num++;
			printf("%d\n",num/2);
		}
	}
	return 0;
}