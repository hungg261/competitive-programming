/******************************************************************************
Link: https://codeforces.com/contest/449/problem/D
Code: 449D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-25-16.20.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int powmod(int a, int b, int m = MOD){
    a %= m;
    int res = 1 % m;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

const int MAXN = 1e6, MAXVAL = 1e6, MAXLG = __lg(MAXVAL) + 1;
int n, a[MAXN + 5];
int dp[1 << MAXLG], f[1 << MAXLG];

inline int NOT(int x){ return x ^ ((1 << MAXLG) - 1); }

void solve(){
    for(int i = 0; i < MAXLG; ++i){
        for(int mask = 0; mask < (1 << MAXLG); ++mask){
            if(mask >> i & 1){
                dp[mask] += dp[mask ^ (1 << i)];
            }
        }
    }

    int res = 0;
    for(int mask = (1 << MAXLG) - 1; mask >= 0; --mask){
        int x = NOT(mask);
        int cnt = __builtin_popcount(x);

        int delta = powmod(2, dp[mask]);
        if(cnt & 1) res -= delta;
        else res += delta;

        res %= MOD;
    }

    cout << (res + MOD) % MOD << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        dp[NOT(a[i])]++;
    }

    solve();

    return 0;
}
