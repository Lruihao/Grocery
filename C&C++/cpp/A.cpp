#include "bits/stdc++.h"
using namespace std;
int main(){
    int a[200005];
    int n;
    int i;
    while(cin>>n){
        for(i=0;i<=n;i++)
            cin>>a[i];
        int sum=a[n];
        for(i=n;i>=0;){
            if(sum>=i){
                cout<<i<<endl;
                break;
            }
            else sum+=a[--i];
        }
        if(i<0)
            cout<<"0"<<endl;
    }
    return 0;
}
