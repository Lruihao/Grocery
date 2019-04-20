#include<bits/stdc++.h>
using namespace std;

int a,b,c;
int used[111][111][111];
struct node
{
	int x,y,z;
	int step;
}m,n;


int bfs()
{
	queue<node>q;
	m.x = a;
	m.y = 0;
	m.z = 0;
	m.step = 0;
	used[a][0][0] = 1;
	q.push(m);
	while (!q.empty())
	{
		int trans;		//��ˮ��
		m = q.front();
		q.pop();

		//�ɹ��ֺõ��������
		if ((m.x == 0 && m.y == m.z) || (m.y == 0 && m.x == m.z) || (m.z == 0 && m.x == m.y))
			return m.step;

		//���濪ʼ6����������һ������������������ˮ��
		if (m.x)
		{
			//��һ
			trans = min(m.x , b - m.y);//�Լ�ģ��һ�µ�ˮ���̾�֪����
				n.x = m.x - trans;
				n.y = m.y + trans;
				n.z = m.z;
				n.step = m.step + 1;
				if (!used[n.x][n.y][n.z])
				{
					q.push(n);
					used[n.x][n.y][n.z] = 1;
				}

			//�ڶ�
			trans = min(m.x , c - m.z);
				n.x = m.x - trans;
				n.y = m.y;
				n.z = m.z + trans;
				n.step = m.step + 1;
				if (!used[n.x][n.y][n.z])
				{
					q.push(n);
					used[n.x][n.y][n.z] = 1;
				}
		}
		if (m.y)
		{
			//����
			trans = min(m.y , a - m.x);
				n.x = m.x + trans;
				n.y = m.y - trans;
				n.z = m.z;
				n.step = m.step + 1;
				if (!used[n.x][n.y][n.z])
				{
					used[n.x][n.y][n.z] = 1;
					q.push(n);
				}

			//����
			trans = min(m.y , c - m.z);
				n.x = m.x;
				n.y = m.y - trans;
				n.z = m.z + trans;
				n.step = m.step + 1;
				if (!used[n.x][n.y][n.z])
				{
					used[n.x][n.y][n.z] = 1;
					q.push(n);
				}
		}
		if (m.z)
		{
			//����
			trans = min(m.z , a - m.x);
				n.x = m.x + trans;
				n.y = m.y;
				n.z = m.z - trans;
				n.step = m.step + 1;
				if (!used[n.x][n.y][n.z])
				{
					used[n.x][n.y][n.z] = 1;
					q.push(n);
				}

			//����
			trans = min(m.z , b - m.y);
				n.x = m.x;
				n.y = m.y + trans;
				n.z = m.z - trans;
				n.step = m.step + 1;
				if (!used[n.x][n.y][n.z])
				{
					q.push(n);
					used[n.x][n.y][n.z] = 1;
				}
		}
	}
	return 0;
}

int main()
{
	while (~scanf ("%d %d %d",&a,&b,&c) && (a || b || c))
	{
		if (a&1)		//�ȼ򵥵ļ�֦һ��,�����϶�����ƽ��
			printf ("NO\n");
		else
		{
			memset (used,0,sizeof (used));
			int ans = bfs();
			if (ans)
				printf ("%d\n",ans);
			else
				printf ("NO\n");
		}
	}
	return 0;
}
