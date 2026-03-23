#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Segment{
    int l, r, p, q;

    Segment() = default;
    Segment(int _l, int _r, int _p, int _q): l(_l), r(_r), p(_p), q(_q){}

    bool operator < (const Segment& other) const{
        return l < other.l;
    }

    operator int() const{ return this->l; }
};

int powmod(int a, int b, int mod){
    a %= mod;
    int res = 1;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

const int MOD = 998244353;
const int MAXN = 2e5, MAXM = 2e5;
int n, m;
int pref[MAXN + 5], inv[MAXN + 5], inv_q[MAXN + 5];
Segment segments[MAXN + 5];

int dp[MAXM + 5];
void solve(){
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        Segment& seg = segments[i];
        int L = lower_bound(segments + 1, segments + n + 1, seg.l) - segments;
        int R = upper_bound(segments + 1, segments + n + 1, seg.r) - segments - 1;

        int mul = pref[R] * powmod(pref[L - 1], MOD - 2, MOD) % MOD * inv[i] % MOD * (seg.p * inv_q[i] % MOD) % MOD;
        dp[seg.r] = (dp[seg.r] + dp[seg.l - 1] * mul % MOD) % MOD;
    }

    cout << (dp[m] + MOD) % MOD << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    pref[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= n; ++i){
        int l, r, p, q;
        cin >> l >> r >> p >> q;

        segments[i] = Segment(l, r, p, q);
    }
    sort(segments + 1, segments + n + 1);
    for(int i = 1; i <= n; ++i){
        Segment& seg = segments[i];
        inv_q[i] = powmod(seg.q, MOD - 2, MOD);

        inv[i] = powmod((seg.q - seg.p) * inv_q[i], MOD - 2, MOD);
        pref[i] = pref[i - 1] * ((seg.q - seg.p) * inv_q[i] % MOD) % MOD;
    }

    solve();

    return 0;
}
