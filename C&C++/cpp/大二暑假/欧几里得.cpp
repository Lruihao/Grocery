#include<cstdio>
#include<cmath>
long long a,b,c,x1,x2,yy1,y2,x0,yy0;
inline long long cmin(const long long &x,const long long &y) {return x<y?x:y;}
inline long long cmax(const long long &x,const long long &y) {return x>y?x:y;}

long long gcd(long long a,long long b)
{
    if (b==0) return a;
    return gcd(b,a % b);
}
void exgcd(long long a,long long b)
{
    if (b==0){x0=1;yy0=0;return;}
    exgcd(b,a%b);
    long long t=x0;x0=yy0;yy0=t-a/b*yy0;
    return;
}

int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&x1,&x2,&yy1,&y2);
    c=-c;
    if (c<0) {a=-a;b=-b;c=-c;}
    if (a<0) {a=-a;long long t=x1;x1=-x2;x2=-t;}
    if (b<0) {b=-b;long long t=yy1;yy1=-y2;y2=-t;}
    if (a==0 && b==0)
    {
        if (c==0)
        {
            printf("%I64d",(x2-x1+1)*(y2-yy1+1));
            return 0;
        }
        printf("0");return 0;
    }
    else if (a==0)
    {
        if (c %b ==0)
            if (c/b<=y2 && c/b>=yy1) {printf("%I64d",x2-x1+1);return 0;}
        printf("0");return 0;
    }
    else if (b==0)
    {
        if (c%a==0)
            if (c/a<=x2 && c/a>=x1) {printf("%I64d",y2-yy1+1);return 0;}
        printf("0");return 0;
    }

    long long d=gcd(a,b);
    if (c%d!=0){printf("0");return 0;}

    a=a/d;b=b/d;c=c/d;
    exgcd(a,b);
    x0=x0*c;yy0=yy0*c;

    double tx2=x2,tx1=x1,tx0=x0,ta=a,tb=b,tc=c,ty1=yy1,ty2=y2,ty0=yy0;
    long long down1=floor(((tx2-tx0)/tb)),down2=floor(((ty0-ty1)/ta));
    long long r=cmin(down1,down2);
    long long up1=ceil(((tx1-tx0)/tb)),up2=ceil(((ty0-ty2)/ta));
    long long l=cmax(up1,up2);
    if (r<l) printf("0");
    else printf("%I64d",r-l+1);
    return 0;

}
