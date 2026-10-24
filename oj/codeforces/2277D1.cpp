/******************************************************************************
Link: https://codeforces.com/contest/2277/problem/D1
Code: 2277D1
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-24-19.43.21
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXLG = 61;
const int MOD = 998'244'353;

int f(int n){
    if(n == 0) return 0;

    int lg = 63 - __builtin_clzll(n + 1);

    int bmin = ((1LL << lg) == n + 1) ? lg : lg + 1;
    int best = bmin + (1LL << bmin) - 1 - n;

    int left = n - (1LL << lg) + 2;
    if(left < n) best = min(best, lg + 1 + f(left));


    return best;
}

void solve(){
    int l, r;
    cin >> l >> r;

    int res = 0;
    for(int i = l; i <= r; ++i)
        res = (res + f(i)) % MOD;

    cout << res << "\n";
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
