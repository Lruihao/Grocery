#include<bits/stdc++.h>
using namespace std;

int n,m,s;
char maze[107][107];
int vx[8]={-1,1,0,0,-1,-1,1,1};
int vy[8]={0,0,-1,1,-1,1,1,-1};

void dfs(int x,int y){
    maze[x][y]='*';
    for(int i=0;i<8;i++){
        int tx=x+vx[i];
        int ty=y+vy[i];
        if(tx>=0&&tx<m&&ty>=0&&ty<n&&maze[tx][ty]=='@')
            dfs(tx,ty);
    }
}

int main(){
    int i,j;
    while(cin>>m>>n&&m){
        s=0;
        for(i=0;i<m;i++)
            cin>>maze[i];
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(maze[i][j]=='@'){
                    dfs(i,j);
                    s++;
                }
            }
        }
        cout<<s<<endl;
    }
	return 0;
}
