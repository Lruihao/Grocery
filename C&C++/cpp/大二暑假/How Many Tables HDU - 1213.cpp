#include<bits/stdc++.h>
using namespace std;

int pre[1005];

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

int main(){
    int n,m,t,sum,root1,root2;
    cin>>t;
    while(t--){
        cin>>n>>m;
        sum=n;
        for(int i=1;i<=n;i++)
            pre[i]=i;
        for(int i=0;i<m;i++){
            cin>>root1>>root2;
            int xx=find(root1);
            int yy=find(root2);
            if(xx!=yy){
                pre[xx]=yy;
                sum--;
            }
        }
        cout<<sum<<endl;
    }
	return 0;
}
