/******************************************************************************
Link: https://marisaoj.com/problem/245
Code: 245
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-12-08.40.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n, m;
vector<pair<int, int>> adj[MAXN + 5];

bool joint[MAXN + 5];
int bridges = 0, articulations = 0;

int tin[MAXN + 5], low[MAXN + 5], Time = 0;
void dfs_tree(int u, int prv){
    tin[u] = low[u] = ++Time;

    int children = 0;
    for(const pair<int, int>& e: adj[u]){
        int v, idx; tie(v, idx) = e;
        if(idx == prv) continue;

        if(!tin[v]){
            dfs_tree(v, idx);
            low[u] = min(low[u], low[v]);

            if(prv == -1){
                ++children;
                if(children > 1) joint[u] = true;
            }
            else if(low[v] >= tin[u]) joint[u] = true;

            if(low[v] > tin[u]) ++bridges;
        }
        else low[u] = min(low[u], tin[v]);

    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    for(int u = 1; u <= n; ++u) if(!tin[u]) dfs_tree(u, -1);
    for(int u = 1; u <= n; ++u) articulations += joint[u];

    cout << articulations << ' ' << bridges << '\n';

    return 0;
}
