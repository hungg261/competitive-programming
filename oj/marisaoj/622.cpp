/******************************************************************************
Link: https://marisaoj.com/problem/622
Code: 622
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-03-18.44.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXVAL = 2e6;
const int MOD = 1e9 + 7;
int fact[MAXVAL + 5];

void compute(){
    fact[0] = 1;
    for(int i = 1; i <= MAXVAL; ++i){
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

int C(int n, int k){
    if(n < k || n < 0 || k < 0) return 0;
    return fact[n] * powmod(fact[k] * fact[n - k], MOD - 2, MOD) % MOD;
}

int solve(int n, int S, int R){
    int res = 0;
    for(int i = 0; i <= n; ++i){
        int mul = (i & 1) ? -1 : 1;
        res += mul * C(n, i) * C(S + n - 1 - (R + 1) * i, n - 1) % MOD;
        res %= MOD;
    }

    return (res + MOD) % MOD;
}


signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int S, n, L, H;
	cin >> S >> n >> L >> H;

    compute();

    cout << solve(n, S - L * n, H - L) << '\n';

	return 0;
}
