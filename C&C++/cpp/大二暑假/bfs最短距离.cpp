/*������һ��n��m�е��Թ���ÿ����λҪô�ǿյ�(��1��ʾ)Ҫô���ϰ���(��0��ʾ).
����ҵ�����㵽�յ�����·��������BFS�������𲽼����ÿ���ڵ㵽������̾��룬
�Լ����·��ÿ���ڵ��ǰһ���ڵ㡣���ս�����һ�������Ϊ����BFS������ʱBFS�����������һ�㵽���ľ��롣
*/
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=100+5;

int G[maxn][maxn];   //��ͼ��d=id
int path[maxn];      //��ÿ���ڵ�ĸ��ڵ㣬��·��
int n,m;             //n��   m��
int k=1;//��¼���
int end_num;
int vx[5] = {-1,1,0,0};   //vx  vy��������һ���ڵ���Χ��������4���ڵ�
int vy[5] = {0,0,-1,1};
bool vis[maxn][maxn];     //�ж�ĳ�ڵ��Ƿ��Ѿ������ʹ�

struct node
{
    int x;
    int y;
    int id;
    int parent=0;
    node(int a,int b,int c)
    {
        x=a;
        y=b;
        id=c;
    }
};

int main()
{
    //freopen("in.txt","r",stdin);
    memset(G,0,sizeof(G));
    memset(vis,0,sizeof(vis));
    memset(path,0,sizeof(path));
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            cin>>G[i][j];
        }
    queue<node> q;
    node v=node(1,1,1);
    q.push(v);
    vis[1][1]=1;
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        path[u.id]=u.parent;//��¼ÿ����ĸ��ڵ�
        for(int i=0; i<4; i++)
        {
            int tx=u.x+vx[i];
            int ty=u.y+vy[i];
            if(G[tx][ty]&&!vis[tx][ty])
            {
                vis[tx][ty]=1;
                //cout<<tx<<ty<<endl;
                node v=node(tx,ty,++k);
                end_num=k;
                v.parent=u.id;
                q.push(v);
            }
        }
    }
    vector<int> ans;
    //cout<<end_num<<endl;
    while(end_num)//�Ӻ��濪ʼ�Ҹ��׽ڵ�
    {
        ans.push_back(end_num);
        end_num=path[end_num];
    }
    int s=0;
    while(!ans.empty())
    {
        s++;
        cout<<*(ans.end()-1)<<' ';//ans���һ��Ԫ����0������
        ans.pop_back();
    }
    cout<<endl<<s-1;
    cout<<endl;
    return 0;
}
