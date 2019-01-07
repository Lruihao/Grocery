#include <stdio.h>
int a[6]={1,2,5,10,50,100};
int one(int t)
{
	int s=0;
	for (int i=5;t;i--)
	{
		s+=t/a[i];
		t%=a[i];
	}
	return s;
}

int main()
{
	int n,t,s,i;
	while (scanf("%d",&n),n)
	{
		s=0;
		for (i=0;i<n;i++)
		{
			scanf("%d",&t);
			s+=one(t);
		}
		printf("%d\n",s);
	}
	return 0;
}
 
