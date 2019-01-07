#include <stdio.h>
int min(int a,int b)
{
	int i,t;
	if (a<b)
	{t=a;a=b;b=t;}
	for (i=1;;i++)
	{
		t=i*a;
		if (t%b==0)
			return t;
	}
}
int main()
{
	int n,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&a);
		while(--n)
		{
			scanf("%d",&b);
			a=min(a,b);
		}
		printf("%d\n",a);
	}
	return 0;
}
 
