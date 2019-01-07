#include<stdio.h>
#include<math.h>
#define maxn 200
double a[maxn][maxn];
int main()
{
    int i,j,k,n;
    int x1,x2,y1,y2;
    a[0][0]=0;
    for(k=1;k<maxn;k++)
		for(i=0;i<=k;i++)
		{
			j=k-i;
			if(i==0)
				a[0][j]=a[j-1][0]+sqrt(j*j+(j-1)*(j-1));
			else a[i][j]=a[i-1][j+1]+sqrt(2);
		}    
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%.3lf\n",fabs(a[x2][y2]-a[x1][y1]));
		}     
		return 0;
}

