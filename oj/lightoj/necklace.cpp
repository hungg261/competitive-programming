/******************************************************************************
Link: https://lightoj.com/problem/necklace
Code: necklace
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-30-15.11.42
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int powmod(int a, int b, int mod = MOD){
    int res = 1 % mod;
    a %= mod;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, k;
    cin >> n >> k;

    int res = 0;
    for(int i = 1; i <= n; ++i){
        res = (res + powmod(k, __gcd(i, n))) % MOD;
    }
    res = res * powmod(n, MOD - 2) % MOD;
    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    for(int tc = 1; tc <= t; ++tc){
        cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
}
