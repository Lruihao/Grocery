#include "bits/stdc++.h"
using namespace std;

int main(){
    int a[10],b[6];
    while(cin>>b[0]){
         memset(a,0,sizeof(a));
    int B=0,E=0;
            a[b[0]]++;
    for(int i=1;i<6;i++){
        cin>>b[i];
        a[b[i]]++;
    }
    int f=0;
    for(int i=0;i<10;i++){
        if(a[i]!=0){
            f++;
        }
        if(a[i]==1){
            B++;
        }
            else if(a[i]==2){
                E++;
            }
    }
    if(f==3&&B==2||f==2&&B==1)
        cout<<"Bear"<<endl;
    else if(f==2&&E==1||f==1)
        cout<<"Elephant"<<endl;
    else cout<<"Hernia"<<endl;
    }
    return 0;
}
