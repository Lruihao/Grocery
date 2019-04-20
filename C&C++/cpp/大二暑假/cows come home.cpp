#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int INF=99999999;                    //设为无穷大
int maps[1005][1005],v[1005],d[1005];  //v表示是否已经过遍历 d表示从源到点当前最短路
int n;

void Dijkstra(int s,int t)
{
    int i,j,k,mini;
    for(i=1;i<=n;i++)
        d[i]=INF;
    d[s]=0;

    for(i=1;i<=n;i++){//找出n个k,找n个点
        mini=INF;
        k=-1;
        for(j=1;j<=n;j++)
            if(!v[j]&&d[j]<mini)
                mini=d[k=j];
        v[k]=1;
        if(k==t){
            printf("%d\n",d[t]);
            return ;
        }

        for(j=1;j<=n;j++){
            if(!v[j]&&(d[k]+maps[k][j])<d[j])
                d[j]=d[k]+maps[k][j];
        }
    }
}

int main()
{
    int T,i,j,x,y,D;
    while(scanf("%d %d",&T,&n)!=EOF)
    {
        memset(v,0,sizeof(v));
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                maps[i][j]=INF;
        for(i =1;i<=T;i++){
            scanf("%d%d%d",&x,&y,&D);   //可能有多条路，只记录最短的
            if(maps[x][y]>D)
                maps[x][y]=maps[y][x]=D;
        }
        Dijkstra(1,n);
    }
    return 0;
}
