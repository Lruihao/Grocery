#include"stdio.h"
double zuhe(int n,int m)
{
	double s=1,i;
	for(i=0;i<m;i++)
		s=s*(n-i)/(i+1);
	return s;
}
int main( )
{
	int n,m,i;
	double s[20],sum;
	s[1]=0;s[2]=1;
	for(i=3;i<20;i++)
		s[i]=(i-1)*(s[i-1]+s[i-2]);
	while(scanf("%d",&n), n!=0)
	{ 
		sum=0;
		if(n%2==0)
			m=n/2;
		else
			m=(n+1)/2;
		for(i=m;i<n;i++)
			sum=sum+zuhe(n,i)*s[n-i];
		printf("%.lf\n",sum+1);
	}
	return 0;
}