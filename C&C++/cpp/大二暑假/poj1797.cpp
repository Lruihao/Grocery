#include<iostream>
#include<cstdio>
#define min(a,b) (a<b?a:b)
using namespace std;

int n,m,v[1010],maps[1010][1010],d[1010];//��ʱd��ʾ1��ÿһ�������ͨ������������

int dijkstra(){
    int i,j,k;
    for(i=1;i<=n;i++){
        v[i]=0;
        d[i]=maps[1][i];//���ʱ��d���������·�������Ǵ�1��n����������
    }
    for(i=1;i<=n;i++){//n����
        int f=-1;
        for(j=1;j<=n;j++)
            if(!v[j]&&d[j]>f){
                f=d[j];
                k=j;
            }
        v[k]=1;
        for(j=1;j<=n;j++)
            if(!v[j]&&d[j]<min(d[k],maps[k][j]))//����˵����ͼ��
                d[j]=min(d[k],maps[k][j]);
    }
    return d[n];
}

int main(){
    int ans=1;
    int a,b,w;
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				maps[i][j]=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&w);
            maps[a][b]=maps[b][a]=w;
        }
        printf("Scenario #%d:\n%d\n\n",ans++,dijkstra());

    }
	return 0;
}
