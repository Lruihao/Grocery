#include <bits/stdc++.h>
#define inf 0x3f3f3f3f     //acm中“无穷大”的一般定义
using namespace std;

const int M=202;
char mp[M][M];            //地图
int a[M][M],b[M][M];
bool vis[M][M];           //标记数组
int n,m;
int ans;
struct node
{
    int x,y,step;
};

void init()              //初始化函数
{
    ans=inf;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            a[i][j]=inf;
            b[i][j]=inf;
        }
}

void bfs(int x,int y,bool flag){
    int dir[4][2]={-1,0,1,0,0,1,0,-1};
    node u,v;
    queue<node> q;  //初始化队列第一个元素
    u.x=x;
    u.y=y;
    u.step=0;
    vis[x][y]=true;
    q.push(u);
    while(!q.empty()){
        u=q.front();
        q.pop();
        if(mp[u.x][u.y]=='@'){
            if(!flag) a[u.x][u.y]=u.step;
            else b[u.x][u.y]=u.step;
        }
        for(int i=0;i<4;i++){
            int tx=u.x+dir[i][0];
            int ty=u.y+dir[i][1];
            if(tx>=0&&ty>=0&&tx<n&&ty<m&&!vis[tx][ty]&&mp[tx][ty]!='#'){//注意@和M，Y也是可以走的。
                v.x=tx;                                          //每次写搜索都忘记vis!!!!
                v.y=ty;
                vis[tx][ty]=true;  //我总是忘记。。。
                v.step=u.step+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=0; i<n; i++)
            scanf("%s",mp[i]);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(mp[i][j]=='Y')
                {
                    memset(vis,false,sizeof(vis));
                    bfs(i,j,false);
                }
                if(mp[i][j]=='M')
                {
                    memset(vis,false,sizeof(vis));  //记得再次初始化标记数组
                    bfs(i,j,true);
                }
            }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(mp[i][j]=='@')
                    ans=min(ans,a[i][j]+b[i][j]);
        printf("%d\n",ans*11);
    }
    return 0;
}
