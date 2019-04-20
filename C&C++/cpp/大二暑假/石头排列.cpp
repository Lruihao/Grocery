#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m,ans;
    scanf("%lld%lld",&n,&m);
    ans=m;
    for(int i=1;i<n;i++)
        ans=(ans*(m-1))%1000000007;
    printf("%lld\n",ans);
	return 0;
}
