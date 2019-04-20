#include "iostream"
#include "cstring"
using namespace std;
int pre[1005];
int x[1005],y[1005],use[1005];

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

void join(int x,int y){
    int fx=findd(x),fy=findd(y);
    if(fx!=fy)
        pre[fx]=fy;
}

int dis(int i,int num,int d){
    d=d*d;
    int xx=x[i]-x[num];
    int yy=y[i]-y[num];
    if((xx*xx+yy*yy)<=d)
        return 1;
    return 0;
}

int main(){
    int n,d;
    char s;
    memset(use,0,sizeof(use));
    cin>>n>>d;
    for(int i=0;i<=n;i++)
        pre[i]=i;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    while(cin>>s){
        if(s=='O'){
            int num;
            cin>>num;
            use[num]=1;
            findd(num);//Â·¾¶Ñ¹Ëõ
            for(int i=1;i<=n;i++)
                if(i!=num&&use[i]==1&&dis(i,num,d))
                    join(i,num);
        }
        else if(s=='S'){
            int q,p;
            cin>>q>>p;
            if(findd(q)==findd(p))
                cout<<"SUCCESS"<<endl;
            else cout<<"FAIL"<<endl;
        }
    }
    return 0;
}
