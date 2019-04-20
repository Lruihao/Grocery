#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,i,j,s=0;
    int n1[10000],m1[100]={0};
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>n1[i];
    for(j=0;j<m;j++)
        m1[j]=n1[j];

    if(n==m){
        sort(m1,m1+m,greater<int>());
        s=m1[0];
    }
    else {

    for(j;j<n;){
        sort(m1,m1+m,greater<int>());
        s+=m1[m-1];
        for(i=0;i<m;i++)
            m1[i]-=m1[m-1];
        //cout<<"test:"<<s<<endl;
        for(i=0;i<m&&j<n;i++){
            if(m1[i]==0)
                m1[i]=n1[j++];
        }
        if(j==n){sort(m1,m1+m,greater<int>());s+=m1[0];break;}
    }

    }
    cout<<s;
    return 0;
}
