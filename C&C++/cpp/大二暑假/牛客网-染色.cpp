
#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e5+10;

int a[MAXN];

map<int, int >ma;

set<int>se;

int x[MAXN],y[MAXN];

int main()

{

    int n;

    scanf("%d",&n);

    for (int i = 1; i <=n ; ++i) {

        scanf("%d",&a[i]);

        se.insert(a[i]);

    }



    for (int i = 1; i <n ; ++i) {

        scanf("%d%d",&x[i],&y[i]);

    }

    long long ans=1e14,sum=0;

    set<int>::iterator it;

    for (it=se.begin(); it !=se.end() ; ++it) {

        sum=0;

        for (int j = 1; j <=n ; ++j) {

            if((*it)!=a[j]) sum+=((*it)+a[j]);

        }

        ans=min(sum,ans);

    }

    printf("%lld\n",ans);

    return 0;

}

/*
#include<bits/stdc++.h>
using namespace std;
int a[1000000],n,m,k=1,t,ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<=n;++i)
        if(a[i]!=a[1])
            ans+=a[i]+a[1];
    printf("%d",ans);
    return 0;
}

*/
