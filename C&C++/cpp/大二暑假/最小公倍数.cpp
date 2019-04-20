#include<bits/stdc++.h>
using namespace std;

unsigned long long gcd(unsigned long long a,unsigned long long b){
    return a%b==0?b:gcd(b,a%b);
}
int main(){
    unsigned long long a,b;
    cin>>a>>b;
    unsigned long long c=a*(b/gcd(a,b));//ע�ⱬlong long
    cout<<c;
	return 0;
}
