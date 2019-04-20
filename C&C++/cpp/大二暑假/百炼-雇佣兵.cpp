#include<iostream>
using namespace std;

int main(){
    int m,n,x;
    cin>>m>>n>>x;
    while(x>0){
        if(n>m)break;
        int t=m/n;
        if(m%n!=0)t++;
        if(t>x) break;
        x-=t;
        t=m/n;
        n+=t;
    }
    cout<<n;
    return 0;
}
