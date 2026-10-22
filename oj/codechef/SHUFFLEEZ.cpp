/******************************************************************************
Link: https://www.codechef.com/START258D/problems/SHUFFLEEZ
Code: SHUFFLEEZ
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-30-22.38.15
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998244353, INVMOD = 499122177;
const int MAXN = 2e5;
int fact[MAXN + 5];

void compute(){
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i)
        fact[i] = fact[i - 1] * i % MOD;
}

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

int n, k, q[MAXN + 5];

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> q[i];
    }

    int res = fact[k] * powmod(k, n - k) % MOD;
    cout << (res + MOD) % MOD << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    compute();

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
