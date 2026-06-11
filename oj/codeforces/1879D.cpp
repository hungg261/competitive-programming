/******************************************************************************
Link: https://codeforces.com/problemset/problem/1879/D
Code: 1879D
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-11-07.08.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    long long res = 0;
    for(int b = 0; b < 31; ++b){
        long long P[2] = {}; int C[2] = {};
        long long prefix = 0; ++C[0];
        for(int i = 1; i <= n; ++i){
            prefix += (a[i] >> b & 1);

            int bit = prefix & 1;
            P[bit] += i; P[bit] %= MOD;
            C[bit]++;

            res += (1LL << b) % MOD * (1LL * i * C[bit ^ 1] % MOD - P[bit ^ 1] % MOD + MOD) % MOD;
            res %= MOD;
        }
    }

    cout << (res % MOD + MOD) % MOD << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
