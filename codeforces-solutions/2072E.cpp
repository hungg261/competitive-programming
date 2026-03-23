/******************************************************************************
Link: https://codeforces.com/problemset/problem/2072/E
Code: 2072E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-07-21.42.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int k;
    cin >> k;

    int x = -1e9, y = -1e9;
    vector<pair<int, int>> res;
    while(k > 0){
        int mx = (sqrt(k * 8 + 1) + 1 + 1e-9) / 2;
        k -= mx * (mx - 1) / 2;

        while(mx--){
            res.emplace_back(x++, y);
        }
        ++y;
    }

    cout << res.size() << '\n';
    for(const pair<int, int>& p: res){
        cout << p.first << ' ' << p.second << '\n';
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
