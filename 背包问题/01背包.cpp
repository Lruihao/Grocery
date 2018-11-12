#include<stdio.h>

int main()
{
    int m[21][51] = {{0}},n,i,j,T;
    int w[21]={0};  //花费
    int v[21]={0}; //物体体积

    printf("请输入物品个数：\n");
    scanf("%d",&n);
    printf("请输入各个物品体积：\n");
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    printf("请输入各个物品价值：\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("请输入背包总体积：\n");
    scanf("%d",&T);
    for(i = 1; i<=n; i++)
    {
        for(j = 1; j<=T; j++)
        {
            if(j<v[i])
                m[i][j] = m[i-1][j];
            else
                m[i][j] = m[i-1][j]>(m[i-1][j-v[i]] + w[i])?m[i-1][j]:(m[i-1][j-v[i]] + w[i]);
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",m[n][T]);

    return 0;
}
