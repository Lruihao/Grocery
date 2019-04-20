
#include<bits/stdc++.h>
using namespace std;

int a[4],sum[1005];


int main(){
    int n,s,f1;
    cin>>n;
    for(int j=1;j<=n;j++){
        s=0;
        for(int i=0;i<4;i++){
            cin>>a[i];
            s+=a[i];
        }
        sum[j]=s;
        if(j==1) f1=s;
    }
    sort(sum+1,sum+n+1,greater<int>());

    for(int i=1;i<=n;i++)
        if(sum[i]==f1){
            cout<<i<<endl;
            break;
        }
	return 0;
}
