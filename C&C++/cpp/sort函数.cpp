#include<iostream>
#include<algorithm>
using namespace std;

typedef struct data{
    int a;
    double b;
}date;

bool cmp(date a,date b){
    if(a.b!=b.b) return a.b>b.b;
    return a.a<b.a;
}

int main(){
    date a[3]={{5,56.5},{4,56.5},{8,85}};
    sort(a,a+3,cmp);
    for(int i=0;i<3;i++)
        cout<<a[i].a<<"-"<<a[i].b<<endl;
    cout<<endl;
    return 0;
}
