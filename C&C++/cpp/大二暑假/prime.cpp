#include "bits/stdc++.h"
#define maxx 10000007
using namespace std;

int b[maxx]={1,1,0};

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

void dabiao(){
    for(int i=2;i<=maxx;i++){
        if(!b[i])
            for(int j=i+i;j<=maxx;j+=i)
                b[j]=1;
    }
}

int panduan(int i,int j){
    if(b[i/gcd(i,j)]==0&&b[j/gcd(i,j)]==0){
        return 1;
    }
    else return 0;
}
int main(){
    int i,j,n,k;
    long long sum;
    dabiao();
    while(cin>>n){
        sum=0;
        for(i=2;i<=n;i++)
            for(j=2;j<=n;j++)
                if(panduan(i,j))
                    sum++;
        cout<<sum<<endl;
    }
    return 0;
}
