
/*枚举所有情况
全买双人n%2  0 or 1//剩1个人的时候，可以多开一间房或者退一间2人房开一间3人房
全买3人n%3  0 or 1 or 2
再比较大小
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
        else sum=p2*(n/2)+min(min(p2,p3),p3-p2);//退二买三；

        if(n%3==0)
            sum1=p3*(n/3);
        else if(n%3==1) sum1=p3*(n/3)+min(min(p2,p3),2*p2-p3);//退3买2*2
        else if(n%3==2) sum1=p3*(n/3)+min(p3,p2);//退3买3*2
        cout<<min(sum1,sum)<<endl;
    }
	return 0;
}
