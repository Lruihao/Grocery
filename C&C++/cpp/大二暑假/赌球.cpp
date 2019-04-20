#include<bits/stdc++.h>
using namespace std;

int main(){
    int c[13],d[13]={100,50,20,10,5,2,1,50,20,10,5,2,1};
    int i,t;
    cin>>t;
    int a,b;
    while(t--){
        memset(c,0,sizeof(c));
        cin>>a>>b;
        for(i=0;i<7;i++){
            int x=0;
        if(a>c[i]){
            x=a/d[i];
            c[i]+=x;
            a-=x*d[i];
        }
        }
        for(i=7;i<13;i++){
            int x=0;
        if(b>c[i]){
            x=b/d[i];
            c[i]+=x;
            b-=x*d[i];
        }
        }
        cout<<c[0];
        for(i=1;i<13;i++)
            cout<<" "<<c[i];
        cout<<endl;
    }
	return 0;
}
