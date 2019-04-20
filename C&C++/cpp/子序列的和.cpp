#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b,!(a==0&&b==0)){
        double c=0;
        for(;a<=b;a++)
            c+=(1.0/a)*(1.0/a);
        cout<<fixed<<setprecision(5)<<c<<endl;
    }
    return 0;
}
