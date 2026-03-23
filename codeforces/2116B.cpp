/******************************************************************************
Link: https://codeforces.com/problemset/problem/2116/B
Code: 2116B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-19-20.48.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998244353;
int powmod(int a, int b, int m = MOD){
    int res = 1;
    a %= m;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

void solve(){
    int n;
    cin >> n;

    vector<int> p(n), q(n);
    for(int i = 0; i < n; ++i) cin >> p[i];
    for(int i = 0; i < n; ++i) cin >> q[i];

    int mxp = -1, mxq = -1;
    for(int i = 0; i < n; ++i){
        if(mxp == -1 || p[i] > p[mxp]) mxp = i;
        if(mxq == -1 || q[i] > q[mxq]) mxq = i;

        int res;
        if(make_pair(p[mxp], q[i - mxp]) > make_pair(q[mxq], p[i - mxq]))
            res = powmod(2, p[mxp]) + powmod(2, q[i - mxp]);
        else res = powmod(2, p[i - mxq]) + powmod(2, q[mxq]);

        res %= MOD;
        cout << res << ' ';
    }

    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
