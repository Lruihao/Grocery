#include<iostream>
#include<cstring>
using namespace std;
int map[5][5];
int visited[5][5];
int dx[4]={0, 1, 0, -1};
int dy[4]={ 1, 0,-1, 0};
int head,tail;
struct place{
	int xx,yy;
	int fa;//父节点 
}pla[25],way[25];
void BFS(int x,int y)
{
	int x1,y1;
	head=0,tail=1;
	visited[x][y]=1;
	pla[0].xx=x,pla[0].yy=y;
	while(tail>head)
	{
		x=pla[head].xx;
		y=pla[head].yy;
		//cout<<"("<<x<<", "<<y<<")"<<endl;
		if(x==4&&y==4)
			return ;
		for(int i=0;i<4;i++)
		{
			x1=x+dx[i];y1=y+dy[i];
			//cout<<"("<<x1<<", "<<y1<<")"<<endl;
			if(x1>=0&&x1<=4&&y1>=0&&y1<=4)
				if(map[x1][y1]==0&&!visited[x1][y1])
				{
					pla[tail].xx=x1;
					pla[tail].yy=y1;
					pla[tail].fa=head;
					visited[x1][y1]=1;
					tail+=1;
				}
		}
		head++;
	}
}
int main()
{
	int i,j;
	ios::sync_with_stdio(false);
	memset(map,0,sizeof(map));
	memset(visited,0,sizeof(visited));
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			cin>>map[i][j];
	BFS(0,0);
	i=0;
	while(head)//逆序进行赋值输出就是通路 
	{
		way[i].xx=pla[head].xx;
		way[i].yy=pla[head].yy;
		i++;
		head=pla[head].fa;
	}
	way[i].xx=0;way[i].yy=0;
	while(i!=-1)
	{
		cout<<"("<<way[i].xx<<", "<<way[i].yy<<")"<<endl;
		i--;
	}
	return 0;
}
