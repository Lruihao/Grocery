#include <stdio.h>
void ranking(double a[]);
int main()
{
    double x[4],y[4];
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3])!=EOF)
    {
        if((x[0]<=x[2]&&x[1]<=x[2]&&x[0]<=x[3]&&x[1]<=x[3])||(x[0]>=x[2]&&x[1]>=x[2]&&x[0]>=x[3]&&x[1]>=x[3])||(y[0]<=y[2]&&y[1]<=y[2]&&y[0]<=y[3]&&y[1]<=y[3])||(y[0]>=y[2]&&y[1]>=y[2]&&y[0]>=y[3]&&y[1]>=y[3]))
            printf("0.00\n");
        else
        {
            ranking(x);
            ranking(y);
            printf("%.2lf\n",(x[2]-x[1])*(y[2]-y[1]));
        }
    }
    return 0;
}
void ranking(double a[])
{
    double tem;
    for(int i=0;i<3;i++)
        for(int j=0;j<3-i;j++)
        {
            if(a[j]>a[j+1])
            {
                tem=a[j];
                a[j]=a[j+1];
                a[j+1]=tem;
            }
        }
}
 
