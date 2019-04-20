#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL mod_pow(LL x, LL n, LL p){
    LL res = 1;
    while(n){
        if(n & 1) res =res * x % p;
        x = x * x % p;
        n >>= 1;
    }
    return res;
}

LL comb(LL n, LL m, LL p){
    if(m > n) return 0;
    LL ret = 1;
    m = min(n - m, m);
    for(int i = 1; i <= m; i ++){
        LL a = (n + i - m) % p;
        LL b = i % p;
        ret = ret * (a * mod_pow(b, p - 2, p) % p) % p;
    }
    return ret;
}

LL Lucas(LL n, LL m, LL p){
    if(m == 0) return 1;
    return comb(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

int main(){
    int T;
    LL n, m, p;
    scanf("%d", &T);
    while(T--){
        scanf("%lld %lld %lld", &n, &m, &p);
        printf("%lld\n", Lucas(n, m, p));
    }
    return 0;
}
