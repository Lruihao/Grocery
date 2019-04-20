#include<bits/stdc++.h>
using namespace std;

long long sum;

int main(){
    int n;
    int t;
    cin>>t;
    while(t--){
        sum=1;
        cin>>n;
        if(n==1) sum=0;
        for(int i=3;i<=n;i++)
            sum+=i-1;
        cout<<sum<<endl;
    }
	return 0;
}
