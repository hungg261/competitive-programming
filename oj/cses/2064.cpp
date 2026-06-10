#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6;
const int MOD = 1e9 + 7;
int fact[MAXN + 5];

void compute(int n){
    fact[0] = 1;
    for(int i = 1; i <= n; ++i){
        fact[i] = fact[i - 1] * i % MOD;
    }
}

int powmod(int a, int b, int mod = MOD){
    int res = 1 % mod;
    a %= mod;

    while(b > 0){
        if(b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }

    return res;
}

int C(int n, int k, int mod = MOD){
    return 1LL * fact[n] * powmod(1LL * fact[k] * fact[n - k], MOD - 2) % mod;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    if(n & 1){
        cout << 0 << '\n';
        return 0;
    }

    compute(n);
    n >>= 1;

    int ans = ((C(n * 2, n) - C(n * 2, n - 1)) % MOD + MOD) % MOD;

    cout << ans << '\n';

    return 0;
}
