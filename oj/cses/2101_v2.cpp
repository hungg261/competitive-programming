/******************************************************************************
Link: https://cses.fi/problemset/task/2101
Code: 2101
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-20-10.24.27
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz;

    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
    }

    void init(){
        for(int i = 1; i <= n; ++i){
            create(i);
        }
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

    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;

        if(sz[a] < sz[b]) swap(a, b);

        par[b] = a;
        sz[a] += sz[b];

        return true;
    }
};

const int MAXN = 2e5, MAXLG = __lg(MAXN * 2 + 5);
int n, m, q;

struct Edge{
    int u, v, w;

    bool operator < (const Edge& other) const{
        return w < other.w;
    }
};

vector<Edge> edges;
int val[MAXN * 2 + 5];
vector<int> tree[MAXN * 2 + 5];
int table[MAXN * 2 + 5][MAXLG + 5], h[MAXN * 2 + 5];
int head;

bool mark[MAXN * 2 + 5];
void dfs(int u, int prv){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: tree[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        table[v][0] = u;

        dfs(v, u);
    }
}

void compute(){
    for(int u = head; u >= 1; --u) dfs(u, 0);
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i <= n * 2; ++i){
            table[i][j] = table[table[i][j - 1]][j - 1];
        }
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

void KRT(){
    sort(begin(edges), end(edges));
    DSU dsu(n * 2);
    dsu.init();

    head = n;
    for(int i = 0; i < m; ++i){
        const Edge& e = edges[i];
        int fu = dsu.find(e.u), fv = dsu.find(e.v);
        if(fu == fv) continue;

        ++head;
        tree[head].push_back(fu);
        tree[head].push_back(fv);
        val[head] = e.w;

        dsu.par[fu] = dsu.par[fv] = head;
        dsu.sz[head] = dsu.par[fu] + dsu.par[fv];
    }

    compute();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        edges.push_back({a, b, i});
    }

    KRT();
    val[0] = -1;

    while(q--){
        int u, v;
        cin >> u >> v;

        int res = val[find_lca(u, v)];
        cout << res << '\n';
    }

    return 0;
}
