#include <bits/stdc++.h>
using namespace std;

string s, ans;

int main(){
    cin >> s;
    int one = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0') ans += "0";
        if (s[i] == '1') one++;
        if (s[i] == '2') ans += "2";
    }
    bool flag = false;
    for (int i = 0; i < ans.size(); i++){
        if (ans[i] == '2' && !flag) flag = true, cout << string(one, '1');
        cout << ans[i];
    }
    if (!flag) cout << string(one, '1');
    return 0;
}

/*

100210

11222121

20

2001

020201

2012101

111

000

*/
