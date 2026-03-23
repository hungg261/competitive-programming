#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
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

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    int rotate_odd = powmod(2, (n / 2) * (n / 2));
    if(n & 1) rotate_odd = rotate_odd * powmod(2, n / 2 + 1) % MOD;

    int rotate_even = powmod(2, n * n);
    int rotate_sym = powmod(2, (n / 2) * (n / 2)) * powmod(2, (n / 2) * (n / 2)) % MOD;
    if(n & 1) rotate_sym = rotate_sym * powmod(2, n / 2) % MOD * powmod(2, n / 2) % MOD * 2 % MOD;

    int ans = (rotate_odd * 2 + rotate_even + rotate_sym) % MOD * powmod(4, MOD - 2) % MOD;
    cout << ans << '\n';

    return 0;
}
