
#include<stdio.h>

#include <string.h>

int chess[8][8];

int vist_col[8];  //列标记

int status;  //状态计数器

int n,k;



void DFS(int row,int num)  //逐行搜索，row为当前搜索行，num为已填充的棋子数

{

    int j;

    if(num==k)//放完了

    {

        status++;

        return;

    }

    if(row==n)    //配合下面DFS(row+1,num); 语句使用，避免搜索越界

        return;



    for(j=0; j<n; j++)

        if(chess[row][j] && !vist_col[j])

        {

            vist_col[j]=1;  //放置棋子的列标记

            DFS(row+1,num+1);

            vist_col[j]=0; //回溯后，说明摆好棋子的状态已记录，当前的列标记还原

        }



    DFS(row+1,num);   //搜索在下一行放棋子的情况
    //这里是难点，当k<n时，row在等于n之前就可能已经把全部棋子放好

    //又由于当全部棋子都放好后的某个棋盘状态已经在前面循环时记录了

    //因此为了处理多余行，令当前位置先不放棋子，搜索在下一行放棋子的情况

    return;

}



int main(int i,int j)

{

    while(scanf("%d%d",&n,&k)!=EOF)

    {

        getchar();

        if(n==-1 && k==-1)

            break;

        memset(chess,0,sizeof(chess));

        memset(vist_col,0,sizeof(vist_col));

        status=0;

        for(i=0; i<n; i++)

        {

            for(j=0; j<n; j++)

            {

                char temp;

                //cin>>temp;

                scanf("%c",&temp);

                if(temp=='#')

                {

                    chess[i][j]=1;

                }

            }

            getchar();

        }



        DFS(0,0);  //注意初始化的值别弄错了

        printf("%d\n",status);

    }

    return 0;

}
