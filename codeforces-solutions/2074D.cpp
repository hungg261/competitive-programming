/******************************************************************************
Link: https://codeforces.com/problemset/problem/2074/D
Code: 2074D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-30-22.25.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int llsqrt(int x){ return (int)(sqrt(x) + 1e-9); }
int pow2(int x){ return x * x; }

void solve(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pos(n);
    for(int i = 0; i < n; ++i) cin >> pos[i].first;
    for(int i = 0; i < n; ++i) cin >> pos[i].second;

    map<int, int> mp;
    for(int i = 0; i < n; ++i){
        int xi, ri; tie(xi, ri) = pos[i];
        for(int x = xi - ri; x <= xi + ri; ++x){
            mp[x] = max(mp[x], llsqrt(pow2(ri) - pow2(x - xi)));
        }
    }

    int res = 0;
    for(const auto& p: mp){
        res += p.second * 2 + 1;
    }

    cout << res << '\n';
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
