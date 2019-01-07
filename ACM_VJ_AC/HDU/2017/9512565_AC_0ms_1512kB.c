#include <stdio.h>
int main()
{
	int n,m,cout;char x;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n--)
		{
			cout=0;
			while(1)
			{
				x=getchar();
				m=x;
				if(m>='0'&&m<='9')
					{cout++;}
				if(m==10)
				{
					break;
				}
			}
			printf("%d\n",cout);
		}
		break;
	}
	return 0;
}