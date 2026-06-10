/******************************************************************************
Link: https://codeforces.com/problemset/problem/1761/C
Code: 1761C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-31-18.56.27
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

    vector<string> b(n);
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(b[i][j] == '1') adj[i].push_back(j);
        }
    }

    vector<bool> mark(n, 0);
    vector<int> topo;
    for(int i = 0; i < n; ++i){
        if(!mark[i]) toposort(i, topo, mark, adj);
    }
    reverse(begin(topo), end(topo));

    vector<vector<int>> res(n);
    for(int u: topo){
        res[u].push_back(u);
        sort(begin(res[u]), end(res[u]));
        res[u].erase(unique(begin(res[u]), end(res[u])), end(res[u]));

        for(int v: adj[u]){
            res[v].push_back(u);
        }
    }

    for(int i = 0; i < n; ++i){
        cout << res[i].size() << ' ';
        for(int ele: res[i]) cout << ele + 1 << ' ';
        cout << '\n';
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
