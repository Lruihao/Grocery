#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M, i, j, index=0;
    bool on[5001]; // 记录灯的开关状态
    cin >> N >> M;
    for (i=0; i<5001; i++) on[i] = false; // 第1人
    for (i=2; i<=M; i++){ // 从第2个人开始模拟
        for (j=i; j<=N; j+=i){
            on[j] = !on[j];
        }
    }
    for (i=1; i<=N; i++){
        if (!on[i]){
            if (index == 0) cout << i;
            else cout << "," << i;
            index++;
        }
    }
    cout << endl;
    return 0;
}
