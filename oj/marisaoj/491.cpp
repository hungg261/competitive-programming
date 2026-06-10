/******************************************************************************
Link: https://marisaoj.com/problem/491
Code: 491
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-06-14.58.43
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e5 + 3;
const int MAX = 1000;
int powmod(int a, int b, int m = MOD){
    a %= m;
    int res = 1;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

int nCr[MAX + 5][MAX + 5], fact[MAX + 5];
void compute(){
    fact[0] = 1;
    for(int i = 1; i <= MAX; ++i){
        fact[i] = fact[i - 1] * i % MOD;
    }

    nCr[0][0] = 1;
    for(int i = 1; i <= MAX; ++i){
        nCr[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
        }
    }
}

int C(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    return nCr[n][k];
}

int count(int a, int b, int c, int d, int k){
    int res = 0;
    for(int i = 1; i <= k; ++i){
        res += C(c, i) * C(a, k - i) * C(d, i) * C(b - i, k - i) * fact[i];
    }
    return res;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;

	compute();

	int m = a + c, n = b + d;
    int total = C(n, k) * C(m, k) * fact[k];

//    cerr << C(n, k) << ' ' << C(m, k) << ' ' << fact[k] << '\n';

    cerr << total << ' ' << count(a, b, c, d, k) << '\n';

    int ans = total - count(a, b, c, d, k);
    ans = (ans % MOD + MOD) % MOD;

    cout << ans << '\n';

	return 0;
}
