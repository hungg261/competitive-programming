#include<bits/stdc++.h>
using namespace std;

const long long MAXN = 1e5;
const long long MOD = 1e9 + 7;
long long n, xs[MAXN + 5], ks[MAXN + 5];

long long mod(long long a, long long b){
    return (a % b + b) % b;
}

long long powmod(long long a, long long b, long long mod = MOD){
    long long res = 1 % mod;
    a %= mod;

    while(b > 0){
        if(b % 2 == 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b /= 2;
    }

    return res;
}

long long inverse(long long a, long long mod = MOD){
    return powmod(a, mod - 2, mod);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;

    long long divcnt = 1, divsum = 1;
    long long divcnt_mod = 1, divprod = 0;

    long long value = 1;
    bool perfect_square = true;
    for(long long i = 1; i <= n; ++i){
        long long x, k;
        cin >> x >> k;
        if(k % 2 == 1) perfect_square = false;

        divcnt = divcnt * (k + 1) % MOD;
        divcnt_mod = divcnt_mod * (k + 1) % ((MOD - 1) * 2);

        divsum = divsum * mod(powmod(x, k + 1) - 1, MOD) % MOD * inverse(x - 1) % MOD;

        value = value * powmod(x, k) % MOD;

        xs[i] = x;
        ks[i] = k;
    }

    divcnt_mod /= 2;
    if(perfect_square){
        long long sqrt_value = 1;
        for(long long i = 1; i <= n; ++i){
            sqrt_value = sqrt_value * powmod(xs[i], ks[i] / 2) % MOD;
        }

        divprod = powmod(value, divcnt_mod) * sqrt_value % MOD;
    }
    else{
        divprod = powmod(value, divcnt_mod);
    }

    cout << divcnt << ' ' << divsum << ' ' << divprod << '\n';
    return 0;
}
