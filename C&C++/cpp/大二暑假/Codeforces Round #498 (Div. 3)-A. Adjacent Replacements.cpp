#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a[1001];
    cin>>n;
    int i;
    int flag=0;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(!(a[i]&1)) a[i]--;
        if(!flag) {cout<<a[i];flag=1;}
        else cout<<" "<<a[i];
    }
	return 0;
}
