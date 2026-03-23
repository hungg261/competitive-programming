/******************************************************************************
Link: https://codeforces.com/problemset/problem/652/E
Code: 652E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-12-18.18.49
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct EdgeTo{
    int v, w;
    int rev;
    bool removed;
};

const int MAXN = 3e5;
int n, m;
vector<EdgeTo> adj[MAXN + 5];
int s, t;

namespace Compress{

int tin[MAXN + 5], low[MAXN + 5], Time = 0;
void dfs_tree(int u, int prv){
    tin[u] = low[u] = ++Time;
    for(EdgeTo& e: adj[u]){
        if(e.v == prv) continue;

        if(!tin[e.v]){
            dfs_tree(e.v, u);
            low[u] = min(low[u], low[e.v]);

            if(low[e.v] > tin[u]){
                e.removed = true;
                adj[e.v][e.rev].removed = true;
            }
        }
        else low[u] = min(low[u], tin[e.v]);
    }
}

int bridge_id[MAXN + 5], bID = 0;
vector<int> bridges[MAXN + 5];
void dfs_build(int u, int prv){
    if(bridge_id[u] != 0) return;

    bridge_id[u] = bID;
    bridges[bID].push_back(u);

    for(const EdgeTo& e: adj[u]){
        if(e.removed || e.v == prv) continue;

        dfs_build(e.v, u);
    }
}

vector<int> tree_adj[MAXN + 5];
void compress(){
    for(int u = 1; u <= n; ++u) if(!tin[u]) dfs_tree(u, -1);
    for(int u = 1; u <= n; ++u) if(bridge_id[u] == 0){
        ++bID;
        dfs_build(u, -1);
    }

    for(int u = 1; u <= n; ++u){
        for(const EdgeTo& e: adj[u]){
            if(e.removed){
                tree_adj[bridge_id[u]].push_back(bridge_id[e.v]);
                tree_adj[bridge_id[e.v]].push_back(bridge_id[u]);
            }
        }
    }

    for(int i = 1; i <= bID; ++i){
        sort(tree_adj[i].begin(), tree_adj[i].end());
        tree_adj[i].erase(unique(tree_adj[i].begin(), tree_adj[i].end()), tree_adj[i].end());
    }
}

vector<int> paths;
bool dfs_find(int u, int prv, const int& T){
    if(u == T){
        paths.push_back(u);
        return true;
    }

    for(int v: tree_adj[u]){
        if(v == prv) continue;

        if(dfs_find(v, u, T)){
            paths.push_back(u);
            return true;
        }
    }

    return false;
}

void solve(){
    dfs_find(s, -1, t);
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c, (int)adj[b].size(), false});
        adj[b].push_back({a, c, (int)adj[a].size() - 1, false});
    }
    cin >> s >> t;

    Compress::compress();

    return 0;
}
