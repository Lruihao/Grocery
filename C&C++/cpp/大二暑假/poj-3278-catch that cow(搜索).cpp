#include"iostream"
#include<queue>
#include"string.h"
using namespace std;

int n,k;
bool sign[200007];

struct node{
    int x,step;
};

bool check(int a)
{
    if(!sign[a]&&a>=0&&a<110000)
        return true;
    return false;
}

void bfs()
{
    node u,v;
    queue<node> q;
    v.x=n;//初始化起点
    v.step=0;
    q.push(v);
    sign[v.x]=true;
    while(!q.empty()){
        u=q.front();
        q.pop();
        if(u.x==k){
            cout<<u.step<<endl;
            return ;
        }

        //三种前进方向，左右和闪现
        v=u;
        v.x++;
        v.step++;
        if(check(v.x)){
            sign[v.x]=true;
            q.push(v);
        }

        v=u;
        v.x--;
        v.step++;
        if(check(v.x)){
            sign[v.x]=true;
            q.push(v);
        }

        v=u;
        v.x=2*v.x;
        v.step++;
        if(check(v.x)){
            sign[v.x]=true;
            q.push(v);
        }
    }
}

int main()
{
    cin>>n>>k;
    memset(sign,0,sizeof(sign));
    bfs();
    return 0;
}
