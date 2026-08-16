/******************************************************************************
Link: https://atcoder.jp/contests/abc471/tasks/abc471_e
Code: abc471_e
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-15-19.44.38
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5, MOD = 998'244'353;
int fact[MAXN + 5];

int powmod(int a, int b, int m = MOD){
    int res = 1 % m;
    a %= m;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

void compute(){
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i){
        fact[i] = fact[i - 1] * i % MOD;
    }
}

int C(int n, int k){
    if(n < 0 || k < 0) return 0;
    return fact[n] * powmod(fact[k] * fact[n - k], MOD - 2) % MOD;
}

int n, k, a[MAXN + 5];
int pre[MAXN + 5];



signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    compute();

    int res = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        pre[i] %= MOD;

        res = (res + a[i] * a[i] % MOD) % MOD;
    }

    res *= C(n - 1, k - 1);
    res %= MOD;

    for(int j = 1; j <= n; ++j){
        res += a[j] * pre[j - 1] % MOD * C(n - 2, k - 2) * 2 % MOD;
        res %= MOD;
    }

    cout << res << "\n";

    return 0;
}
