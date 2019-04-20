#include <bits/stdc++.h>
#define inf 0x3f3f3f3f     //acm�С�����󡱵�һ�㶨��
using namespace std;

const int M=202;
char mp[M][M];            //��ͼ
int a[M][M],b[M][M];
bool vis[M][M];           //�������
int n,m;
int ans;
struct node
{
    int x,y,step;
};

void init()              //��ʼ������
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
    queue<node> q;  //��ʼ�����е�һ��Ԫ��
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
            if(tx>=0&&ty>=0&&tx<n&&ty<m&&!vis[tx][ty]&&mp[tx][ty]!='#'){//ע��@��M��YҲ�ǿ����ߵġ�
                v.x=tx;                                          //ÿ��д����������vis!!!!
                v.y=ty;
                vis[tx][ty]=true;  //���������ǡ�����
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
                    memset(vis,false,sizeof(vis));  //�ǵ��ٴγ�ʼ���������
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
