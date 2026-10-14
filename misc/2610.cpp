/******************************************************************************
Link: https://loj.ac/p/2610
Code: 2610
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-14-14.39.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4, MAXLG = __lg(MAXN * 2) + 1;
int n, m;
vector<tuple<int, int, int>> edges;

struct DSU{
    int n;
    vector<int> sz, par;

    DSU(int _n): n(_n){
        sz.resize(n + 1);
        par.resize(n + 1);
        for(int u = 1; u <= n; ++u){
            par[u] = u;
            sz[u] = 1;
        }
    }

    int find(int u){
        return par[u] == u ? u : par[u] = find(par[u]);
    }
};

vector<int> tree[MAXN * 2 + 5];
int table[MAXN * 2 + 5][MAXLG + 5], h[MAXN * 2 + 5];
int val[MAXN * 2 + 5];

void dfs(int u){
    for(int j = 1; j <= MAXLG; ++j)
        table[u][j] = table[table[u][j - 1]][j - 1];

    for(int v: tree[u]){
        h[v] = h[u] + 1;
        table[v][0] = u;
        dfs(v);
    }
}

int lift(int u, int s){
    for(int b = MAXLG; b >= 0; --b){
        if(s >> b & 1) u = table[u][b];
    }
    return u;
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    v = lift(v, h[v] - h[u]);

    if(u == v) return u;

    for(int b = MAXLG; b >= 0; --b){
        if(table[u][b] != table[v][b]){
            u = table[u][b];
            v = table[v][b];
        }
    }
    return table[u][0];
}

void compute(){
    DSU dsu(n * 2);
    sort(begin(edges), end(edges));

    int head = n;
    for(int i = m - 1; i >= 0; --i){
        int u, v, w; tie(w, u, v) = edges[i];
        int a = dsu.find(u), b = dsu.find(v);
        if(a == b) continue;

        ++head;
        tree[head].push_back(a);
        tree[head].push_back(b);
        val[head] = w;

        dsu.par[a] = dsu.par[b] = head;
        dsu.sz[head] = dsu.sz[a] + dsu.sz[b];
    }

    for(int u = 1; u <= head; ++u){
        if(dsu.find(u) == u)
            dfs(u);
    }
}

void solve(){
    compute();
    val[0] = -1;

    int q; cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;

        cout << val[find_lca(u, v)] << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        edges.emplace_back(c, a, b);
    }

    solve();

    return 0;
}
