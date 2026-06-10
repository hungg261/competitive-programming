/******************************************************************************
Link: https://cses.fi/problemset/task/2076
Code: 2076
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-21-18.44.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n, m;
vector<int> adj[MAXN + 5];

vector<pair<int, int>> bridges;
int tin[MAXN + 5], low[MAXN + 5], Timer = 0;
void dfs_tree(int u, int prv){
    tin[u] = low[u] = ++Timer;
    for(int v: adj[u]){
        if(v == prv) continue;

        if(!tin[v]){
            dfs_tree(v, u);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], tin[v]);
    }

    for(int v: adj[u]){
        if(v == prv) continue;

        if(low[v] > tin[u]) bridges.emplace_back(u, v);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int u = 1; u <= n; ++u)
        dfs_tree(u, -1);

    cout << bridges.size() << "\n";
    for(const pair<int, int>& e: bridges){
        cout << e.first << " " << e.second << "\n";
    }

    return 0;
}
