/******************************************************************************
Link: https://codeforces.com/contest/2086/problem/D
Code: 2086D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-01-14.23.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998244353;
const int MAXN = 5e5;
int fact[MAXN + 5];
void compute(){
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i){
        fact[i] = fact[i - 1] * i % MOD;
    }
}

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
    int c[26];
    int n = 0;
    for(int i = 0; i < 26; ++i){
        cin >> c[i];
        n += c[i];
    }

    int o = (n + 1) / 2, e = n - o;
    vector<int> dp(o + 1);
    dp[0] = 1;

    for(int ch = 0; ch < 26; ++ch){
        if(c[ch] == 0) continue;

        for(int j = o; j >= c[ch]; --j){
            dp[j] = (dp[j] + dp[j - c[ch]]) % MOD;
        }
    }

    int ans = fact[o] * fact[e] % MOD;
    for(int ch = 0; ch < 26; ++ch){
        ans = ans * powmod(fact[c[ch]], MOD - 2, MOD) % MOD;
    }
    ans = ans * dp[o] % MOD;

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    compute();

    while(t--){
        solve();
    }

    return 0;
}
