
/*ö���������
ȫ��˫��n%2  0 or 1//ʣ1���˵�ʱ�򣬿��Զ࿪һ�䷿������һ��2�˷���һ��3�˷�
ȫ��3��n%3  0 or 1 or 2
�ٱȽϴ�С
*/
#include<bits/stdc++.h>
#define INF 1<<20
using namespace std;
typedef long long ll;

ll min(ll a,ll b){
    return a<b?a:b;
}

int main(){
    ll n,p2,p3,sum,sum1;
    while(cin>>n>>p2>>p3){
        if(n%2==0)
            sum=p2*(n/2);
        else sum=p2*(n/2)+min(min(p2,p3),p3-p2);//�˶�������

        if(n%3==0)
            sum1=p3*(n/3);
        else if(n%3==1) sum1=p3*(n/3)+min(min(p2,p3),2*p2-p3);//��3��2*2
        else if(n%3==2) sum1=p3*(n/3)+min(p3,p2);//��3��3*2
        cout<<min(sum1,sum)<<endl;
    }
	return 0;
}
