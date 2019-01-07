#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,n,m;
    cin>>n>>m;
    if(n<m){
        cout<<-1<<endl;
        return 0;
    }
    if(n==m){
        cout<<n<<endl;
        return 0;
    }
    if(n%2==0){
        x=n/2%m;
        if(x==0) cout<<n/2<<endl;
        else cout<<n/2+m-x<<endl;
    }else if(n%2!=0){
        x=(n/2+1)%m;
        if(x==0) cout<<n/2+1<<endl;
        else cout<<(n/2+1)+m-x<<endl;
    }
	return 0;
}
