
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

char map[35][35][35];
int vis[35][35][35];
int k,n,m,sx,sy,sz,ex,ey,ez;
int to[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};//上下东西南北

struct node
{
    int x,y,z,step;
};

int check(int x,int y,int z)//检查是否可走
{
    if(x<0 || y<0 || z<0 || x>=k || y>=n || z>=m)//越界判断
        return 1;
    else if(map[x][y][z] == '#')
        return 1;
    else if(vis[x][y][z])
        return 1;
    return 0;
}

int bfs()
{
    int i;
    node a,next;
    queue<node> Q;
    a.x = sx,a.y = sy,a.z = sz;
    a.step = 0;
    vis[sx][sy][sz] = 1;
    Q.push(a);
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        if(a.x == ex && a.y == ey && a.z == ez)
            return a.step;
        for(i = 0; i<6; i++)
        {
            next = a;
            next.x = a.x+to[i][0];
            next.y = a.y+to[i][1];
            next.z = a.z+to[i][2];
            if(check(next.x,next.y,next.z))
                continue;
            vis[next.x][next.y][next.z] = 1;
            next.step = a.step+1;
            Q.push(next);
        }
    }
    return 0;
}

int main()
{
    int i,j,r;
    while(scanf("%d%d%d",&k,&n,&m),n+m+k)
    {
        for(i = 0; i<k; i++)
        {
            for(j = 0; j<n; j++)
            {
                scanf("%s",map[i][j]);
                for(r = 0; r<m; r++)
                {
                    if(map[i][j][r] == 'S')
                    {
                        sx = i,sy = j,sz = r;
                    }
                    else if(map[i][j][r] == 'E')
                    {
                        ex = i,ey = j,ez = r;
                    }
                }
            }
        }
        memset(vis,0,sizeof(vis));
        int ans;
        ans = bfs();
        if(ans)
            printf("Escaped in %d minute(s).\n",ans);
        else
            printf("Trapped!\n");
    }

    return 0;
}
