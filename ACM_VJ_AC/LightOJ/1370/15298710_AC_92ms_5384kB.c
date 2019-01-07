#include<stdio.h>
#define N 1000005
#define ll long long

int m[N]={1,1,0};
int p[100000],cnt=0;

int max(int x,int y){
    return x>y?x:y;
}

void prime(){
    for(int i=2;i<N;i++)
    if(!m[i]){
        for(int j=2*i;j<=N;j+=i)
            m[j]=1;
        p[cnt++]=i;
    }
}

int binary_search(int x){
    int l=0,r=cnt;
    while(l<=r){
        int mid=(l+r)/2;
        if(p[mid]>x)
            r=mid-1;
        else l=mid+1;
    }
    for(int i=max(r,0);;i++)
        if(p[i]>x)
        return p[i];
}

int main(){
    prime();
    int T,n,cas=1,temp;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ll sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&temp);
            sum+=binary_search(temp);
        }
        printf("Case %d: %lld Xukha\n",cas++,sum);
    }
	return 0;
}
