#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char mp[8][8];
int v[8];
int n,k,w,r;//状态计数器r
void dfs(int x)//逐行深搜，x为当前搜索行
{
    if(w==k)//下子数w
    {
        r++;return;
    }
    if(x==n)return;
    for(int i=0;i<n;i++)
    {
        if(v[i]!=1&&mp[x][i]=='#')
        {
            v[i]=1;
            w++;
            dfs(x+1);
            w--;
            v[i]=0;
        }
    }
    dfs(x+1);//搜索下一行
}

int main()
{
    while(cin>>n>>k)
    {
        if(n==-1&&k==-1)
            return 0;
        memset(mp,0,sizeof(mp));
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++)
            cin>>mp[i];
        w=0;r=0;
        dfs(0);
        cout<<r<<endl;
    }
}
