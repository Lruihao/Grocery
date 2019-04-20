#include<iostream>
#include<cstring>
using namespace std;
int map[5][5];
int visited[5][5];
int dx[4]={0, 1, 0, -1};
int dy[4]={ 1, 0,-1, 0};
int head,tail;
struct node{
	int xx,yy;
	int fa;//���ڵ�
}pre[25],way[25];

void BFS(int x,int y)
{
	int x1,y1;
	head=0,tail=1;
	visited[x][y]=1;
	pre[0].xx=x,pre[0].yy=y;

	while(tail>head)//ջ��
	{
		x=pre[head].xx;
		y=pre[head].yy;
		if(x==4&&y==4)//������־
			return ;
		for(int i=0;i<4;i++)
		{
			x1=x+dx[i];y1=y+dy[i];
			if(x1>=0&&x1<=4&&y1>=0&&y1<=4)
				if(map[x1][y1]==0&&!visited[x1][y1])
				{
					pre[tail].xx=x1;
					pre[tail].yy=y1;
					pre[tail].fa=head;
					visited[x1][y1]=1;
					tail+=1;//��ջ
				}
		}
		head++;//�൱�ڳ�ջ
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
	while(head)//������и�ֵ�������ͨ·
	{
		way[i].xx=pre[head].xx;
		way[i].yy=pre[head].yy;
		head=pre[head].fa;
		i++;
	}
	//��һ�¶���
	way[i].xx=0;way[i].yy=0;
	while(i!=-1)
	{
		cout<<"("<<way[i].xx<<", "<<way[i].yy<<")"<<endl;
		i--;
	}
	return 0;
}
