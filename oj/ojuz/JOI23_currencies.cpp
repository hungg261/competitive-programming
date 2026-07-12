/******************************************************************************
Link: https://oj.uz/problem/view/JOI23_currencies
Code: JOI23_currencies
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-09-11.10.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

const int MAXN = 1e5, MAXM = 1e5, MAXQ = 1e5, MAXLG = __lg(MAXN) + 1;
int n, m, q;
vector<int> adj[MAXN + 5];
int table[MAXN + 5][MAXLG + 5], h[MAXN + 5];

vector<pair<int, int>> edges;

int w[MAXN + 5], g[MAXN + 5];

void dfs1(int u = 1, int prv = -1){
    for(int j = 1; j <= MAXLG; ++j)
        table[u][j] = table[table[u][j - 1]][j - 1];

    for(int v: adj[u]){
        if(v == prv) continue;

        table[v][0] = u;
        h[v] = h[u] + 1;
        dfs1(v, u);
    }
}

void dfs2(int u = 1, int prv = -1){
    for(int v: adj[u]){
        if(v == prv) continue;

        g[v] = g[u] + w[v];
        dfs2(v, u);
    }
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);

    if(h[u] != h[v]){
        int diff = h[v] - h[u];
        for(int b = MAXLG; b >= 0; --b)
            if(diff >> b & 1) v = table[v][b];
    }

    if(u == v) return u;

    for(int b = MAXLG; b >= 0; --b){
        if(table[u][b] != table[v][b]){
            u = table[u][b];
            v = table[v][b];
        }
    }

    return table[u][0];
}

inline int calc(int u, int v){ return g[u] + g[v] - g[find_lca(u, v)] * 2; }

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.emplace_back(a, b);
    }

    dfs1();

    for(int i = 1; i <= m; ++i){
        int P, C;
        cin >> P >> C;

        --P;
        int u, v; tie(u, v) = edges[P];
        if(table[v][0] != u) swap(u, v);

        w[v] = C;
    }

    dfs2();



    return 0;
}
