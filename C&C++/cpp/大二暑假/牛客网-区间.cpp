//wa
#include<bits/stdc++.h>
#define N 1000100
using namespace std;

int n,m;
long long s=0,s1,s2=0;
int a[N];
int q[N],L[N],R[N],p[N],l,r;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d%d",&q[i],&L[i],&R[i],&p[i]);
    scanf("%d%d",&l,&r);
    for(int i=l;i<=r;i++)
        s+=a[i];
    for(int i=1;i<=m;i++){
        int x,y;
        x=max(l,L[i]);
        y=min(r,R[i]);
        x=y-x+1;
        s1=p[i]*x;
        if(q[i]) s2-=s1;
        else s2+=s1;
    }
    printf("%lld\n",s+s2);
	return 0;
}
