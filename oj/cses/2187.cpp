#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6;
const int MOD = 1e9 + 7;
int fact[MAXN * 5 + 5];

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
    int total;
    string pre;
    cin >> total >> pre;

    if(total & 1){
        cout << "0\n";
        return 0;
    }

    int len = pre.size();

    int k = 0;
    for(int i = 0; i < len; ++i){
        if(pre[i] == '(') ++k;
        else --k;

        if(k < 0){
            cout << "0\n";
            return 0;
        }
    }

    int n = (total - len - k) / 2;

    compute(n * 2 + k);
    int ans = C(n * 2 + k, n) - C(n * 2 + k, n - 1);
    cout << (ans % MOD + MOD) % MOD << '\n';

    return 0;
}
