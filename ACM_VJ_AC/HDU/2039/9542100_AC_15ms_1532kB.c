#include <stdio.h>
int main ()
{
	int n=0;
	double x=0,y=0,z=0;
	scanf ("%d ",&n);
	while (n--)
	{
		scanf ("%lf %lf %lf",&x,&y,&z);
		printf ((x+y>z&&x+z>y&&y+z>x)?"YES\n":"NO\n");
	}
	return 0;
}
 
