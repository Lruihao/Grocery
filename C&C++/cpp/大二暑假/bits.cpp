#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m,x,y,t;
    n=m=x=y=0;
    char a[100005],b[100005];
    cin>>t;
    cin>>a>>b;
    for(int i=0;i<t;i++){
        int p=a[i]-'0';
        int q=b[i]-'0';
        if(p==0&&q==0) n++;
        if(p==1&&q==0) m++;
        if(p==1&&q==1) x++;
        if(p==0&&q==1) y++;
    }
    long long sum=n*x+m*(y+n);
    cout<<sum<<endl;
	return 0;
}
