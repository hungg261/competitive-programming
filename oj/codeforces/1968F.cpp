/******************************************************************************
Link: https://codeforces.com/problemset/problem/1968/F
Code: 1968F
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-10-17.43.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    map<int, vector<int>> mp;
    vector<int> P(n + 1); P[0] = 0;
    mp[0].push_back(0);
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        P[i] = P[i - 1] ^ cur;

        mp[P[i]].push_back(i);
    }

    while(q--){
        int l, r;
        cin >> l >> r;

        const vector<int> &vL = mp[P[l - 1]], &vR = mp[P[r]];
        int mx = *prev(upper_bound(begin(vL), end(vL), r));
        int mn = *lower_bound(begin(vR), end(vR), l);

        if(mn <= mx) cout << "YES\n";
        else cout << "NO\n";
    }
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
