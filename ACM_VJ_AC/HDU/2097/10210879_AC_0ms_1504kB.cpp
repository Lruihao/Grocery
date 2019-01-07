#include<stdio.h>
int main()
{
	int n,t,s,a,b,c,i;
	while(scanf("%d",&n)&&(n!=0))
	{
		t=s=n;
		a=n%10+n/10%10+n/100%10+n/1000;
		b=0;c=0;
		while(n!=0)
		{
			i=n%16;
			b=b+i;
			n=n/16;
		}
		while(s!=0)
		{
			i=s%12;
			c=c+i;
			s=s/12;
		}
		if(a==b&&a==c)
			printf("%d is a Sky Number.\n",t);
		else
			printf("%d is not a Sky Number.\n",t);
	}
	return 0;
}