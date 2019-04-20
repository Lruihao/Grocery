#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[5],b[107],i,j,sum=0,sum1=0;
    for(i=0;i<5;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+5);
    memset(b,0,sizeof(b));
    for(i=0;i<5;i++)
        b[a[i]]++;
    for(i=0;i<107;i++){
        if(b[i]==2)
            sum1=max(2*i,sum1);
        if(b[i]>=3) {sum1=max(3*i,sum1);/*cout<<3*i<<" "<<sum1<<endl;*/}
    }
    cout<<sum-sum1<<endl;
    return 0;
}
