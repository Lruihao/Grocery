#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M, i, j, index=0;
    bool on[5001]; // ��¼�ƵĿ���״̬
    cin >> N >> M;
    for (i=0; i<5001; i++) on[i] = false; // ��1��
    for (i=2; i<=M; i++){ // �ӵ�2���˿�ʼģ��
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
