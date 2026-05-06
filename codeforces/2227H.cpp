/******************************************************************************
Link: https://codeforces.com/contest/2227/problem/H
Code: 2227H
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-06-20.31.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, leaf[MAXN + 5], maxW[MAXN + 5];
vector<int> adj[MAXN + 5];

void dfs(int u, int prv, int &res){
    leaf[u] = adj[u].size() == 1;
    maxW[u] = 0;

    for(int v: adj[u]){
        if(v == prv) continue;

        dfs(v, u, res);

        bool odd_cnt = leaf[v] & 1;

        leaf[u] += leaf[v];
        maxW[u] = max(maxW[u], maxW[v] + (odd_cnt ? 1 : -1));
        res += odd_cnt;
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int res = 0;
    dfs(1, -1, res);

    if(leaf[1] & 1) res -= maxW[1];
    cout << res << "\n";

    for(int u = 1; u <= n; ++u)
        adj[u].clear();
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
