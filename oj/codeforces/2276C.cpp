/******************************************************************************
Link: https://codeforces.com/contest/2276/problem/C
Code: 2276C
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-14-22.19.05
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> pos(k);
    vector<int> P(n + 1);
    P[0] = 0; pos[0].push_back(0);
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        P[i] = (P[i - 1] + cur) % k;

        pos[P[i]].push_back(i);
    }

    int res = 0;
    for(int i = 1; i <= n; ++i){
        res += upper_bound(begin(pos[P[i]]), end(pos[P[i]]), i - k - 1) - begin(pos[P[i]]);
    }

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
