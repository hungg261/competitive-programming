/******************************************************************************
Link: https://codeforces.com/problemset/problem/1795/D
Code: 1795D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-07-22.12.42
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

int powmod(int a, int b, int m){
    a %= m;
    int res = 1;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    int res = 1;
    for(int i = 1; i <= n; i += 3){
        vector<int> cur;
        cur.push_back(arr[i]);
        cur.push_back(arr[i + 1]);
        cur.push_back(arr[i + 2]);
        sort(begin(cur), end(cur));

        if(cur[0] == cur[1] && cur[1] == cur[2]) res = res * 3 % MOD;
        else if(cur[0] == cur[1]) res = res * 2 % MOD;
    }

    int c = n / 3;
    int half = 1;
    for(int i = 1; i <= c; ++i) res = res * i % MOD;
    for(int i = 1; i <= c / 2; ++i) half = half * i % MOD;

    res = res * powmod(powmod(half, MOD - 2, MOD), 2, MOD) % MOD;

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
