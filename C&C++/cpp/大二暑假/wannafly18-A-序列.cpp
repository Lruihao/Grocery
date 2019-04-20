/*整体来看，a[x] = a[x-1]*[1, -2, 0.5]，那么等于从n-1个[1,-2,0.5]中选出n-1个数值相乘
（a[x-1]=a[x-2]*[1,-2,0.5]同理化简式子），
最后答案要是1，所以-2就必须有偶数个，同理0.5的个数要等于-2.顺序无关.
那所有的转换中，就只要保证有若干组(-2,-2,0.5,0.5)存在，*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
long long c[maxn][maxn];

int main(){
    for(int i = 0; i < maxn; i++){//杨辉三角
        c[i][0] = 1;
        c[i][i] = 1;
        for(int j = 1; j < i; j++)
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }
    int n;
    while(~scanf("%d", &n)){
        n--;
        long long ans = 0;
        for(int i = 0; i*2 <= n; i += 2){
            ans = (ans%mod + (c[n][i]*c[n-i][i])%mod)%mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
