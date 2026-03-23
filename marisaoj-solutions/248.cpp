/******************************************************************************
Link: https://marisaoj.com/problem/248
Code: 248
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-12-11.08.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct EdgeTo{
    int v, eId;
    bool removed = false;

    int rev;
};

const int MAXN = 1e5;
int n, m;
vector<EdgeTo> adj[MAXN + 5];
vector<int> tree_adj[MAXN + 5];

namespace Compress{

int low[MAXN + 5], tin[MAXN + 5], Time = 0;

void dfs_tree(int u, int eID){
    tin[u] = low[u] = ++Time;

    for(EdgeTo& e: adj[u]){
        int v, curID; tie(v, curID) = make_tuple(e.v, e.eId);
        if(curID == eID) continue;

        if(!tin[v]){
            dfs_tree(v, curID);
            low[u] = min(low[u], low[v]);

            if(low[v] > tin[u]){
                e.removed = true;
                adj[v][e.rev].removed = true;
            }
        }
        else low[u] = min(low[u], tin[v]);

    }
}

int bridge_id[MAXN + 5];
int bID;
void dfs(int u){
    if(bridge_id[u] != 0) return;
    bridge_id[u] = bID;

    for(const EdgeTo& e: adj[u]){
        if(e.removed) continue;
        dfs(e.v);
    }
}

void compress(){
    for(int u = 1; u <= n; ++u) if(!tin[u]) dfs_tree(u, -1);
    for(int u = 1; u <= n; ++u){
        if(bridge_id[u] == 0){
            ++bID;
            dfs(u);
        }
    }

    for(int u = 1; u <= n; ++u){
        for(const EdgeTo& e: adj[u]){
            if(e.removed){
                tree_adj[bridge_id[u]].push_back(bridge_id[e.v]);
            }
        }
    }

    for(int i = 1; i <= bID; ++i){
        sort(tree_adj[i].begin(), tree_adj[i].end());
        tree_adj[i].erase(unique(tree_adj[i].begin(), tree_adj[i].end()), tree_adj[i].end());
    }
}

}

bool mark[MAXN + 5];
pair<int, int> dfs_farthest(int u, int prv){
    mark[u] = true;

    pair<int, int> farthest = {0, u}; // depth, node
    for(int v: tree_adj[u]){
        if(v == prv) continue;

        pair<int, int> d = dfs_farthest(v, u);
        d.first++;

        farthest = max(farthest, d);
    }

    return farthest;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back({b, i, false, (int)adj[b].size()});
        adj[b].push_back({a, i, false, (int)adj[a].size() - 1});
    }

    Compress::compress();

    int res = -5;
    for(int u = 1; u <= n; ++u){
        if(!mark[u]){
            int cur = dfs_farthest(dfs_farthest(u, -1).second, -1).first;
            res = max(res, cur);
        }
    }

    cout << res << '\n';

    return 0;
}
