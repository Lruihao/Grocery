#include "bits/stdc++.h"
using namespace std;
struct node{
    long double a,b,c;
    int numb;
}ss[1005];

bool cmp(const node &a,const node &b){
    long double suma,sumb;
    suma=a.a*b.c+a.b*b.c;
    sumb=b.a*a.c+b.b*a.c;
    //suma=(a.a+a.b)/(a.a+a.b+a.c);
    //sumb=(b.a+b.b)/(b.a+b.b+b.c);
    if(suma!=sumb)return suma<sumb;
    return a.numb<b.numb;
}

int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>ss[i].a>>ss[i].b>>ss[i].c;
            ss[i].numb=i+1;
        }
        stable_sort(ss,ss+n,cmp);
        int i;
        for(i=0;i<n-1;i++)
            cout<<ss[i].numb<<" ";
        cout<<ss[i].numb<<endl;
    }
    return 0;
}
