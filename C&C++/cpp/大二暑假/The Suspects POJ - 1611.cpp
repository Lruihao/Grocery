#include<cstdio>

int pre[30010],x[30010];

int find(int root){
    int son,t;
    son=root;
    while(root!=pre[root])
        root=pre[root];
    while(son!=root){
        t=pre[son];
        pre[son]=root;
        son=t;
    }
    return root;
}

void join(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy)
        pre[fy]=fx;
}

int main(){
    int n,m,i,k,sum;
    while(scanf("%d%d",&n,&m),n||m){
        sum=0;
        for(i=0;i<n;i++)
            pre[i]=i;
        while(m--){
            scanf("%d",&k);
            for(i=0;i<k;i++)
                scanf("%d",&x[i]);
            for(i=1;i<k;i++)
                join(x[i-1],x[i]);
        }

        for(i=0;i<n;i++)
            if(find(0)==find(i)) sum++;//再次查找并压缩路径，注不用pre[i]
        printf("%d\n",sum);

    }
	return 0;
}
