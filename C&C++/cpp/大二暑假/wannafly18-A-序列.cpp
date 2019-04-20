/*����������a[x] = a[x-1]*[1, -2, 0.5]����ô���ڴ�n-1��[1,-2,0.5]��ѡ��n-1����ֵ���
��a[x-1]=a[x-2]*[1,-2,0.5]ͬ����ʽ�ӣ���
����Ҫ��1������-2�ͱ�����ż������ͬ��0.5�ĸ���Ҫ����-2.˳���޹�.
�����е�ת���У���ֻҪ��֤��������(-2,-2,0.5,0.5)���ڣ�*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
long long c[maxn][maxn];

int main(){
    for(int i = 0; i < maxn; i++){//�������
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
