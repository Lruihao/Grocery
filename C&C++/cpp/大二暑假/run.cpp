//tle
#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    int q,k,i,j;

    cin>>q>>k;
    while(q--){
        int l,r;
        long long sum=0;
        cin>>l>>r;
        for(i=l;i<=r;i++)
            if(i<k)
                sum=(sum+1)%mod;
            else if(i==k) sum=(sum+2)%mod;
            else{
                sum=(sum+i-k+2)%mod;
                for(j=2;;j++)
                    if((i-j*k)>0){
                        sum=(sum+(i-j*k+1)*(i-j*k)/2)%mod;
                        continue;
                    }
                    else break;

            }
        sum=(sum+mod)%mod;
        cout<<sum<<endl;
    }
return 0;
}
