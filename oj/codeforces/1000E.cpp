/******************************************************************************
Link: https://codeforces.com/contest/1000/problem/E
Code: 1000E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-22-18.48.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int n, m;
vector<int> adj[MAXN + 5];
set<pair<int, int>> bridges;

int tin[MAXN + 5], low[MAXN + 5], Timer = 0;
void dfs_tree(int u, int prv){
    tin[u] = low[u] = ++Timer;
    for(int v: adj[u]){
        if(v == prv) continue;

        if(!tin[v]){
            dfs_tree(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] > tin[u]){
                int x = min(u, v), y = max(u, v);
                bridges.insert({x, y});
            }
        }
        else low[u] = min(low[u], tin[v]);
    }
}

int id[MAXN + 5], Counter = 0;
vector<int> btree[MAXN + 5];
void dfs_number(int u){
    id[u] = Counter;
    for(int v: adj[u]){
        if(id[v]) continue;

        int x = min(u, v), y = max(u, v);
        if(bridges.find({x, y}) != bridges.end()) continue;

        dfs_number(v);
    }
}

pair<int, int> dfs_farthest(int u, int prv){
    pair<int, int> best = {0, u};
    for(int v: btree[u]){
        if(v == prv) continue;

        pair<int, int> cand = dfs_farthest(v, u);
        if(cand.first + 1 > best.first){
            best = {cand.first + 1, cand.second};
        }
    }

    return best;
}

void solve(){
    dfs_tree(1, -1);
    for(int u = 1; u <= n; ++u){
        if(!id[u]){
            ++Counter;
            dfs_number(u);
        }
    }

    for(int u = 1; u <= n; ++u){
        for(int v: adj[u]){
            if(id[u] != id[v]){
                btree[id[u]].push_back(id[v]);
                btree[id[v]].push_back(id[u]);
            }
        }
    }

    for(int i = 1; i <= Counter; ++i){
        sort(begin(btree[i]), end(btree[i]));
        btree[i].erase(unique(begin(btree[i]), end(btree[i])), end(btree[i]));
    }

    cout << dfs_farthest(dfs_farthest(1, -1).second, -1).first << "\n";
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

    solve();

    return 0;
}
