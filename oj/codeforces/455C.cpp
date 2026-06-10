/******************************************************************************
Link: https://codeforces.com/contest/455/problem/C
Code: 455C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-30-10.31.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz;
    vector<int> best;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
        best.resize(n + 1);
    }

    void init(){
        for(int u = 0; u <= n; ++u)
            create(u);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
        best[v] = 0;
    }

    int find(int v){
        return par[v] == v ? v : par[v] = find(par[v]);
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];
            best[a] = max({best[a], best[b], (best[a] + 1) / 2 + (best[b] + 1) / 2 + 1});

            return true;
        }

        return false;
    }
};

const int MAXN = 3e5;
int n, m, q;
vector<int> adj[MAXN + 5];

pair<int, int> dfs_farthest(int u, int prv){
    pair<int, int> best = {0, u};
    for(int v: adj[u]){
        if(v == prv) continue;

        pair<int, int> cand = dfs_farthest(v, u);
        if(best.first < cand.first + 1){
            best = {cand.first + 1, cand.second};
        }
    }

    return best;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;

    DSU dsu(n);
    dsu.init();

    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
        dsu.unite(a, b);
    }

    for(int u = 1; u <= n; ++u){
        if(dsu.par[u] == u){
            dsu.best[u] = dfs_farthest(dfs_farthest(u, -1).second, -1).first;
        }
    }

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            cout << dsu.best[dsu.find(x)] << "\n";
        }
        else if(type == 2){
            int a, b;
            cin >> a >> b;

            dsu.unite(a, b);
        }
    }

    return 0;
}
