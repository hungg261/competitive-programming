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
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = (ans + powmod(k, __gcd(i, n))) % MOD;
    }
    ans = 1LL * ans * powmod(n, MOD - 2) % MOD;

    cout << ans << '\n';

    return 0;
}
