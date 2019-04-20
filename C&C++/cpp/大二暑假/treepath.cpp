#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100010;
vector<int> vs[N];
bool vis[N];
ll ans1, ans2;
void dfs(int x, int de) {
    vis[x] = true;
    for(int i = 0; i < vs[x].size(); i ++) {
        int v = vs[x][i];
        if(!vis[v]) {
            if((de+1) %2) ans1 ++;
            else ans2 ++;
            dfs(v, de+1);
        }
    }
}
void init(){
    ans1 = ans2 = 0;
    memset(vis, false, sizeof(vis));
    for(int i = 1; i < N; i ++) vs[i].clear();
}
int main() {
    int n, x, y;
    while(scanf("%d", &n)!=EOF) {
        init();
        for(int i = 1; i < n; i ++) {
            scanf("%d %d", &x, &y);
            vs[x].push_back(y);
            vs[y].push_back(x);
        }
        dfs(1, 1);
        ans1++;
        // printf("%d %d\n", ans1, ans2);
        ll cnt = (ans1-1)*ans1 + (ans2-1)*ans2;
        printf("%lld\n",cnt/2);
    }
    return 0;
}
