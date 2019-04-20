#include<stdio.h>
const int B = 50000, C = 100000;
int a[150005];
int pro(int x)
{
	while( x != a[x] )
		x = a[x];
	return x;
}
bool same(int x, int y)
{
	return pro(x) == pro(y);
}
void connect(int x, int y)
{
	int temp1 = pro(x), temp2 = pro(y), p;
	a[pro(temp2)] = pro(temp1);
	//Ñ¹ËõÂ·¾¶
	while( y != temp2 )
		 p = y, y = a[y], a[p] = temp1;
}
int main()
{
	int n, k, d, x, y, i, ans;
	scanf("%d%d", &n, &k);
	for( i=0; i<150000; i++) a[i] = i;
	for( i=0, ans=0; i<k; i++)
	{
		scanf("%d%d%d", &d, &x, &y);
		if( x <=0 || y <= 0 || x > n || y > n )
		{
			ans++;
			continue;
		}
		x--, y--;
		if( d == 1 )
			if( same(x, y+B) || same(x, y+C) ) ans++;
			else connect(x, y), connect(x+B, y+B), connect(x+C, y+C);
		else if( same(x, y) || same(x, y+C) ) ans++;
		else connect(x, y+B), connect(x+B, y+C), connect(x+C, y);
	}
	printf("%d\n", ans);
}
