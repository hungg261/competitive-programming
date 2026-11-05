/******************************************************************************
Link: https://codeforces.com/contest/2283/problem/C
Code: 2283C
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-04-22.27.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int len = __lg(n);
    vector<int> res(n + 1, 0);

    int OR = 0, XOR = 0;
    for(int i = 1; i <= n; ++i){
        OR |= i;
    }

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i)
        arr[i] = i;

    for(int b = len + 1; b >= 1; --b){
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            if(arr[i] >> b & 1) ++cnt;
        }

        if(cnt % 2 == 0){
            res[1 << (b - 1)] = 1;
            arr[1 << (b - 1)] *= 2;
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << res[i] << " ";
    }
    cout << "\n";

    for(int i = 1; i <= n; ++i){
        if(res[i]) XOR ^= (i * 2);
        else XOR ^= i;
    }

    assert(XOR >= 2 * OR);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
