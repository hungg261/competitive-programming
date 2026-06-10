#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6;
int fact[MAXN + 5];

void compute(int n){
    fact[0] = 1 % MOD;
    for(int i = 1; i <= n; ++i){
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
}

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

int inverse(int a, int mod = MOD){
    return powmod(a, mod - 2);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;

    int mark[26] = {};
    for(char c: s) ++mark[c - 'a'];

    int n = s.size();
    compute(n);

    int ans = fact[n];
    for(int i = 0; i < 26; ++i){
        ans = (1LL * ans * inverse(fact[mark[i]])) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
