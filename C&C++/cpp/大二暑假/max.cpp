/*
//wa
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,c;
    cin>>c>>n;
    int t=n/c;
    if(t<1) cout<<"-1\n";
    else if(t==1) cout<<c*c<<endl;
    else cout<<(t*c)*((t-1)*c)<<endl;
	return 0;
}*/

//AC
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,c;
    cin>>c>>n;
    long long t=n/c;
    if(t<1) cout<<-1<<endl;
    else if(t==1) cout<<c*c<<endl;
    else cout<<(t*c)*((t-1)*c)<<endl;
	return 0;
}
