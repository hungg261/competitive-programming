#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int factorial(int n, int mod = MOD){
    int res = 1 % mod;
    for(int i = 1; i <= n; ++i) res = 1LL * res * i % mod;

    return res;
}

int powmod(int a, int b, int mod = MOD){
    int res = 1 % mod;
    a %= mod;

    while(b > 0){
        if(b % 2 == 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }

    return res;
}

int inverse(int b, int mod = MOD){
    return powmod(b, mod - 2, mod);
}

int C(int n, int k){
    return 1LL * factorial(n) * inverse(1LL * factorial(k) * factorial(n - k) % MOD) % MOD;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;

    cout << C(n + m - 1, m) << '\n';

    return 0;
}
