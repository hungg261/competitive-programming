/******************************************************************************
Link: https://codeforces.com/problemset/problem/2143/C
Code: 2143C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-01-21.25.27
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void toposort(int u, vector<int>& res, vector<bool>& mark, const vector<vector<int>>& adj){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: adj[u]){
        toposort(v, res, mark, adj);
    }
    res.push_back(u);
}

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; ++i){
        int u, v, x, y;
        cin >> u >> v >> x >> y;

        if(x < y) adj[u].push_back(v);
        else adj[v].push_back(u);
    }

    vector<bool> mark(n + 1, false);
    vector<int> topo;
    for(int i = 1; i <= n; ++i)
        if(!mark[i]) toposort(i, topo, mark, adj);
    reverse(begin(topo), end(topo));

    vector<int> res(n + 1, -1);
    for(int i = 0; i < n; ++i){
        res[topo[i]] = i + 1;
    }

    for(int i = 1; i <= n; ++i){
        cout << res[i] << ' ';
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
