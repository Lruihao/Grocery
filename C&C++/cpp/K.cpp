#include<cstdio>
#include<iostream>
typedef unsigned long long ll;
using namespace std;

int main(){
   ll a,b,c,d;
   while(cin>>a>>b>>c>>d){
        ll ans=0;
        ll num1_1009=b/1009-(a-1)/1009;
        ll num1_2=b/2-(a-1)/2;
        ll num1_1009_2=b/2018-(a-1)/2018;//x是偶数且是1009的倍数
        ll num1_not1009_2=num1_2-num1_1009_2;
        ans+=num1_1009_2*(d-c+1);
        ll num2_1009=d/1009-(c-1)/1009;
        ans+=num1_not1009_2*num2_1009;
        ll num1_not2=b-a+1-num1_2;//奇数个数
        ll num1_1009_not2=num1_1009-num1_1009_2;//2.(1)
        ll num2_2=d/2-(c-1)/2;
        ans+=num1_1009_not2*num2_2;
        ll num1_not1009_not2=num1_not2-num1_1009_not2;
        ll num2_1009_2=d/2018-(c-1)/2018;
        ans+=num1_not1009_not2*num2_1009_2;
        cout<<ans<<endl;
   }
   return 0;
}
//1.若x是偶数：1）若x是1009的倍数，则y可为[c,d]中任意数； 2）若x不是1009的倍数，则y必定为[c,d]中1009的倍数
//2.若x是奇数：1）若x是1009的倍数，则y必定为[c,d]中2的倍数； 2）若x不是1009的倍数，则y必定为[c,d]中2018的倍数
