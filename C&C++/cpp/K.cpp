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
        ll num1_1009_2=b/2018-(a-1)/2018;//x��ż������1009�ı���
        ll num1_not1009_2=num1_2-num1_1009_2;
        ans+=num1_1009_2*(d-c+1);
        ll num2_1009=d/1009-(c-1)/1009;
        ans+=num1_not1009_2*num2_1009;
        ll num1_not2=b-a+1-num1_2;//��������
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
//1.��x��ż����1����x��1009�ı�������y��Ϊ[c,d]���������� 2����x����1009�ı�������y�ض�Ϊ[c,d]��1009�ı���
//2.��x��������1����x��1009�ı�������y�ض�Ϊ[c,d]��2�ı����� 2����x����1009�ı�������y�ض�Ϊ[c,d]��2018�ı���
