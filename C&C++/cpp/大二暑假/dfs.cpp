#include <bits/stdc++.h>
#define N 5
using namespace std;
int maze[N][N] = {//��Ȩ����ͼ
     { 0, 1, 0, 1, 0 },
     { 0, 0, 1, 0, 0 },
     { 0, 0, 0, 0, 1 },
     { 0, 0, 1, 0, 0 },
     { 0, 0, 0, 0, 0 }
 };
 int visited[N];
 void DFS(int start)
 {
     cout << start<< " ";
     visited[start] = 1;
     for (int i = 0; i < N; i++)
     {
         if (!visited[i] && maze[start][i] == 1)//û���ʹ���Ϊ�ھӽڵ�
             DFS(i);
     }
 }
 void BFS(int start){
     queue<int> Q;//����
     Q.push(start);
     visited[start] = 1;
     while (!Q.empty())
     {
         int front = Q.front();//ͷ
         cout << front << " ";
         Q.pop();
         for (int i = 0; i <N; i++)
         {
             if (!visited[i] && maze[front][i] == 1)
             {
                 visited[i] = 1;
                 Q.push(i);
             }
         }
     }
 }

 int main()
 {
     memset(visited,0,sizeof(visited));
     for (int i = 0; i < N; i++)//����ͨ�����
     {
         if (visited[i] == 1)//���ʹ�
             continue;
         DFS(i);
     }
     cout<<endl;
     memset(visited,0,sizeof(visited));
     for (int i = 0; i < N; i++)//����ͨ�����
     {
         if (visited[i] == 1)//���ʹ�
             continue;
         BFS(i);
     }
     return 0;
 }
