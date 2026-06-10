/******************************************************************************
Link: https://codeforces.com/contest/2110/problem/D
Code: 2110D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-11-22.37.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> b(n + 1);

    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].emplace_back(b, c);
    }

    const int INF = 1e9;
    auto check = [&](int mid){
        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        for(int u = 1; u <= n; ++u){
            if(u > 1 && dp[u] == 0) continue;

            dp[u] += b[u];
            dp[u] = min(dp[u], mid);

            for(const pair<int, int>& p: adj[u]){
                int v, w;
                tie(v, w) = p;

                if(dp[u] >= w)
                    dp[v] = max(dp[v], dp[u]);
            }
        }

        return dp[n] > 0;
    };

    if(!check(INF)){
        cout << -1 << '\n';
        return;
    }

    int l = 0, r = 1e15, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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
