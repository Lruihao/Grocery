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
    if(count==19)//m���200λ
        return ;
    dfs(x*10,count+1);
    dfs(x*10+1,count+1);
    //ÿ��λ������λ�����������10��11����������������ҵ�һ�־ͷ��أ��Ҳ���������һ������
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
