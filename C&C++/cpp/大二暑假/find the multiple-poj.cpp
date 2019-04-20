#include"iostream"
using namespace std;
typedef unsigned long long ll;
int n;
bool sign;

void dfs(ll x,int count)
{
    if(sign)
        return ;
    if(x%n==0){
        sign=true;
        cout<<x<<endl;
        return ;
    }
    if(count==19)//m最多200位
        return ;
    dfs(x*10,count+1);
    dfs(x*10+1,count+1);
    //每两位数后两位有两种情况，10或11，深搜所有情况，找到一种就返回，找不到找另外一颗子树
}
int main()
{
    while(cin>>n&&n)
    {
        sign=false;
        dfs(1,0);
    }
    return 0;
}
