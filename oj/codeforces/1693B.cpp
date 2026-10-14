/******************************************************************************
Link: https://codeforces.com/problemset/problem/1693/B
Code: 1693B
Time: 2026-10-14-09.31.01
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int n, dp[MAXN + 5];
struct Range{ int l, r; } RANGES[MAXN + 5];
vector<int> adj[MAXN + 5];

int dfs(int &res, int u = 1, int prv = -1){
    int total = 0;
    for(int v: adj[u]){
        if(v == prv) continue;
        total += dfs(res, v, u);
    }

    if(total < RANGES[u].l) ++res, total += RANGES[u].r;
    return min(RANGES[u].r, total);
}

void solve(){
    cin >> n;
    for(int u = 1; u <= n; ++u){
        adj[u].clear();
    }

    for(int u = 2; u <= n; ++u){
        int p; cin >> p;
        adj[p].push_back(u);
        adj[u].push_back(p);
    }

    for(int u = 1; u <= n; ++u){
        cin >> RANGES[u].l >> RANGES[u].r;
    }

    int res = 0;
    dfs(res);
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
