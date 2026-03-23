/******************************************************************************
Link: https://marisaoj.com/problem/247
Code: 247
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-12-08.30.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct EdgeTo{
    int v;
    int idx;
    bool is_bridge;
};

const int MAXN = 1e5;
int n, m;
vector<EdgeTo> adj[MAXN + 5];

int tin[MAXN + 5], low[MAXN + 5], Time = 0;
void dfs_tree(int u, int prv){
    tin[u] = low[u] = ++Time;

    for(EdgeTo& e: adj[u]){
        int v = e.v;
        if(v == prv) continue;

        if(!tin[v]){
            dfs_tree(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] > tin[u]){
                e.is_bridge = true;
            }
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

        adj[a].push_back({b, i, false});
        adj[b].push_back({a, i, false});
    }

    for(int u = 1; u <= n; ++u) if(!tin[u]) dfs_tree(u, -1);

    vector<int> res;
    for(int u = 1; u <= n; ++u){
        for(const EdgeTo& e: adj[u]){
            if(e.is_bridge){
                res.push_back(e.idx);
            }
        }
    }
    sort(begin(res), end(res));

    cout << res.size() << '\n';
    for(int i: res){
        cout << i << ' ';
    }

    return 0;
}
