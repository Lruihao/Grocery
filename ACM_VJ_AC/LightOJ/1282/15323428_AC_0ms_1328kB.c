#include<stdio.h>
#include<math.h>

typedef long long LL;

int quickpow (int m, int n, int k)
{
    int b = 1;
    while (n > 0)
    {
        if (n & 1)
            b = (b * m) % k;
        n >>= 1;
        m = (m * m) % k;
    }
    return b%k;
}

int main ()
{
    int t, flag = 1;
    scanf ("%d", &t);

    while (t--)
    {
        LL n, k;
        scanf ("%lld %lld", &n, &k);

        int first = pow (10.0, 2.0 + fmod (k*log10(n*1.0), 1));
        int last = quickpow (n%1000, k, 1000);

        printf ("Case %d: %d %03d\n", flag++, first, last);
    }
    return 0;
}
