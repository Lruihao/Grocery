#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
int pre[200010],ranks[200010];

int find(int root){
    if(pre[root] != root)
    {
        int f = pre[root];
        pre[root] = find(pre[root]);//�ݹ�·��ѹ��
        ranks[root] += ranks[f];
        /*�������һ��ʼû��ϵ����ô��rank��������ʾa��b���Ե��������ȵľ��롣
        ��ô�ڰ�a�����ȸ�b�����ȵ�����֮����ôb�����ȵľ���Ҳ����rank[b]��Ҫ�ټ���bԭ�������ȵ�a�����ȵľ��룬����һ�£�
        ����find�������Ҹ��ڵ�ĺ�������rank[x]+=rank[pre[x]]������pre�������Ƕ�Ӧ���ĸ��ڵ㣩*/
    }
    return pre[root];
}

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        int ans=0;
        for(int i=1; i<=n; i++)
            pre[i]=i;
        memset(ranks,0,sizeof(ranks));
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            a--;//[a,b]~~(a--,b]
            int fa=find(a);
            int fb=find(b);
            if(fa!=fb){
                pre[fb]=fa;//ע��ϲ�˳�򣬷����������ҲҪ��
                ranks[fb]=ranks[a]-ranks[b]+c;//���¾���
            }
            else {
                if(ranks[b]-ranks[a]!=c)
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
