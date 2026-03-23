#include<bits/stdc++.h>
using namespace std;

const int MAXVAL = 1e6, MOD = 1e9 + 7;
int fact[MAXVAL + 5];

int powmod(int a, int b, int mod = MOD){
    int res = 1 % mod;
    a %= mod;

    while(b > 0){
        if(b % 2 == 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b /= 2;
    }

    return res;
}

void compute(){
    fact[0] = 1 % MOD;
    for(int i = 1; i <= MAXVAL; ++i){
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    }
}

int inverse(int a, int mod = MOD){
    return powmod(a, mod - 2, mod);
}

int C(int n, int k, int mod = MOD){
    return 1LL * fact[n] * inverse(1LL * fact[k] * fact[n - k] % mod) % mod;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;

    compute();
    while(t--){
        int n, k;
        cin >> n >> k;

        cout << C(n, k) << '\n';
    }
    return 0;
}
