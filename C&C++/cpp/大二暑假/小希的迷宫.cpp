#include<bits/stdc++.h>
using namespace std;

int pre[100001];

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

void join(int a,int b){
    int x=find(a),y=find(b);
    if(x!=y)
        pre[y]=x;
}

int main(){
    int a,b,flag,i,sum;
	while(1)
	{
		flag = 0;
		while(~scanf("%d%d",&a,&b) && a!=0 && b!=0){
			if(a==-1 && b==-1) return 0;
            if(pre[a]==0)pre[a]=a;
			if(pre[b]==0)pre[b]=b;
			if(find(a)==find(b))flag = 1;
			else if(flag!=1)
			join(a,b);
		}
        for(sum = 0,i=1;i<100001;i++){
            if(pre[i]==i)sum++;
            pre[i] = 0;
        }
        if(sum>1 || flag == 1)
			printf("No\n");
        else
			printf("Yes\n");
	}
}
//1 2 3 4 0 0 No 没有联通
