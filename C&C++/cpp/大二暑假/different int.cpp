#include<bits/stdc++.h>
#define N 100005
using namespace std;

int main(){
    int n,q;
    int i,j,k,a[N],u[N];
    int l,r,sum;
    memset(a,0,sizeof(a));
    memset(u,0,sizeof(u));
    while(cin>>n>>q){
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=q;i++){
            cin>>l>>r;
            k=1;
            for(j=1;j<=l;j++)
                u[k++]=a[j];
            for(j=r;j<=n;j++)
                u[k++]=a[j];
            sort(u,u+k);
            sum=unique(u,u+k)-u-1;
            cout<<sum<<endl;
        }
    }
	return 0;
}
