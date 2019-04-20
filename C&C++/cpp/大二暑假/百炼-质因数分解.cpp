#include<iostream>
using namespace std;
int n;
int i;
int main(){
    cin>>n;
    for(i=2;i<=n;i++)
        if(n%i==0){cout<<n/i;break;}
    return 0;
}
