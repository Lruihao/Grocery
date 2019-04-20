#include<iostream>
#include<string.h>
#include<map>
using namespace std;
#define MAX 100005
int father[MAX],sum[MAX];
int total;
map<string,int>A;//用map来处理人名与数字下标之间的对应关系

int find_set(int x)
{
    if(x!=father[x])
        father[x]=find_set(father[x]);
    return father[x];
}
void union_set(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if(x!=y)
    {
        father[x]=y;
        sum[y]+=sum[x];
    }
}

int main()
{
    int t,n;
    string a,b;
    while(cin>>t)
    {
        while(t--)
        {
            total=0;
            A.clear();
            cin>>n;
            while(n--)
            {
                cin>>a>>b;
                if(A.find(a)==A.end())
                {
                    total++;
                    A[a]=total;
                    father[total]=total;
                    sum[total]=1;

                }
                if(A.find(b)==A.end())
                {
                    total++;
                    A[b]=total;
                    father[total]=total;
                    sum[total]=1;
                }
                union_set(A[a],A[b]);
                int ans=find_set(A[b]);
                cout<<sum[ans]<<endl;
            }
        }
    }
    return 0;
}
