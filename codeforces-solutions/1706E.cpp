/******************************************************************************
Link: https://codeforces.com/contest/1706/problem/E
Code: 1706E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-11-09.33.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
    }

    void init(){
        for(int u = 0; u <= n; ++u)
            create(u);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
    }

    int find(int v){
        return par[v] == v ? v : par[v] = find(par[v]);
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }
};

const int MAXN = 1e5, MAXTREE = MAXN * 2, MAXLG = __lg(MAXN) + 1;
vector<int> tree[MAXTREE + 5];
int val[MAXTREE + 5];
int table[MAXTREE + 5][MAXLG + 5], h[MAXTREE + 5];

void dfs(int u){
    for(int v: tree[u]){
        table[v][0] = u;
        h[v] = h[u] + 1;

        dfs(v);
    }
}

void compute(int tot){
    dfs(tot);

    int LG = __lg(tot) + 1;
    for(int j = 1; j <= LG; ++j){
        for(int i = 1; i <= tot; ++i){
            table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
}

int lift(int u, int s){
    for(int bit = MAXLG; bit >= 0; --bit){
        if(s >> bit & 1){
            u = table[u][bit];
        }
    }
    return u;
}

int lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    v = lift(v, h[v] - h[u]);

    if(u == v) return u;

    for(int bit = MAXLG; bit >= 0; --bit){
        if(table[u][bit] != table[v][bit]){
            u = table[u][bit];
            v = table[v][bit];
        }
    }
    return table[u][0];
}

struct Edge{
    int u, v, w;

    bool operator < (const Edge& other) const{
        return w < other.w;
    }
};

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<Edge> edges;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        edges.push_back({a, b, i});
    }

    DSU dsu(n * 2);
    dsu.init();
    int cnt = n;

    for(int i = 1; i <= n; ++i){
        val[i] = 0;
        tree[i].clear();
    }
    for(const Edge& e: edges){
        int u = dsu.find(e.u),
            v = dsu.find(e.v);
        if(u == v) continue;

        ++cnt;
        tree[cnt].clear();
        tree[cnt].push_back(u);
        tree[cnt].push_back(v);
        val[cnt] = e.w;

        dsu.par[u] = dsu.par[v] = cnt;
        dsu.sz[cnt] = dsu.sz[u] + dsu.sz[v];
    }

    compute(cnt);

    int LG = __lg(n);
    vector<vector<int>> lca_range(n + 1, vector<int>(LG + 1));
    for(int i = 1; i <= n; ++i) lca_range[i][0] = i;
    for(int j = 1; j <= LG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++i){
            lca_range[i][j] = lca(lca_range[i][j - 1], lca_range[i + (1 << (j - 1))][j - 1]);
        }
    }

    while(q--){
        int u, v;
        cin >> u >> v;

        int bit = __lg(v - u + 1);
        int res = lca(lca_range[u][bit], lca_range[v - (1 << bit) + 1][bit]);

        cout << val[res] << ' ';
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
