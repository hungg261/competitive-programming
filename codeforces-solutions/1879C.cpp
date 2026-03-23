/******************************************************************************
Link: https://codeforces.com/problemset/problem/1879/C
Code: 1879C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-08-12.47.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int powmod(int a, int b, int m){
    int res = 1;
    a %= m;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

const int MOD = 998244353;
void solve(){
    string s;
    cin >> s;

    int n = s.size();
    int res = 1, cur = 1, cnt = 1;
    for(int i = 1; i < n; ++i){
        if(s[i - 1] != s[i]){
            res = res * cur % MOD;
            cur = 1;
            ++cnt;
        }
        else{
            ++cur;
        }
    }
    res = res * cur % MOD;

    int left = n - cnt;
    for(int i = 1; i <= left; ++i){
        res = res * i % MOD;
    }

    cout << n - cnt << ' ' << res << '\n';
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
