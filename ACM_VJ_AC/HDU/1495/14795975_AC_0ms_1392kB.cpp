#include<bits/stdc++.h>
using namespace std;

int main(){
    int s,n,m;
    while(cin>>s>>n>>m,s+n+m){
        s/=__gcd(n,m);
        if(s&1)//奇数
            cout<<"NO\n";
        else cout<<s-1<<endl;
    }
    return 0;
}