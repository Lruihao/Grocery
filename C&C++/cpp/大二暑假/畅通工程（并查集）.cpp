#include<iostream>
#include<cstdio>
using namespace std;
int pre[1010];

int findd(int root){
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

int main(){
    int n,m,i,sum,r1,r2,star,end1;
    while(scanf("%d",&n)&&n){
        sum=n-1;
        for(i=1;i<=n;i++)
            pre[i]=i;
        scanf("%d",&m);
        while(m--){
            scanf("%d%d",&star,&end1);
            r1=findd(star);
            r2=findd(end1);
            if(r1!=r2){
                pre[r1]=r2;
                sum--;
            }
        }
        printf("%d\n",sum);
    }
	return 0;
}
