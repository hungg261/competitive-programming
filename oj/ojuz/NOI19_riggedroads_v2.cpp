// ICPC HCMUS Training Round #1 - In-contest Code

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5, MAXE = 3e5;
int N, E;

struct EdgeTo{ int v, id; };
vector<EdgeTo> adj[MAXN + 5];

struct Edge{ int u, v, id, w; };
vector<Edge> edges;

//namespace Brute{
//
//void solve(){
//    vector<int> res(N, N + 1);
//    vector<int> perm(E);
//    iota(begin(perm), end(perm), 1);
//
//    auto it
//
//    do{
//
//
//    } while(next_permutation(begin(perm), end(perm)));
//
//}
//
//}

namespace Solve{

const int MAXLG = __lg(MAXN) + 1;
int h[MAXN + 5], table[MAXN + 5][MAXLG + 5];
int ids[MAXN + 5];

struct DSU{
    int n;
    vector<int> par, sz, mn;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
        mn.resize(n + 1);
    }

    void init(){
        for(int v = 0; v <= n; ++v){
            par[v] = v;
            sz[v] = 1;
            mn[v] = v;
        }
    }

    int find(int v){ return par[v] == v ? v : par[v] = find(par[v]); }

    void unite(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return;

        if(sz[a] < sz[b]) swap(a, b);

        par[b] = a;
        sz[a] += sz[b];
        mn[a] = h[mn[a]] < h[mn[b]] ? mn[a] : mn[b];
    }
};

void dfs(int u = 1, int prv = -1){
    for(int j = 1; j <= MAXLG; ++j)
        table[u][j] = table[table[u][j - 1]][j - 1];

    for(const EdgeTo& e: adj[u]){
        if(e.v == prv) continue;

        h[e.v] = h[u] + 1;
        table[e.v][0] = u;
        ids[e.v] = e.id;

        dfs(e.v, u);
    }
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);

    {
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

DSU dsu;
int Counter = 0;
void add_path(int u, int v){
    int lca = find_lca(u, v);

    vector<int> path;
    while(h[u] > h[lca]){
        int uid = dsu.find(u);
        path.push_back(u);

        int old = u;
        u = table[dsu.mn[uid]][0];
        if(h[u] > h[lca]){
            dsu.unite(old, u);
        }
    }

    while(h[v] > h[lca]){
        int vid = dsu.find(v);
        path.push_back(v);

        int old = v;
        v = table[dsu.mn[vid]][0];
        if(h[v] > h[lca]){
            dsu.unite(old, v);
        }
    }

    sort(begin(path), end(path), [&](int a, int b){
            return ids[a] < ids[b];
         });

    int sz = path.size();
    for(int i = 0; i < sz; ++i){
        int idx = ids[path[i]];
        if(edges[idx].w == -1) edges[idx].w = ++Counter;
    }
//    cerr << endl;
}

void solve(){
    vector<int> in(E + 1, 0);
    for(int i = 1; i < N; ++i){
        int idx; cin >> idx;

        const Edge& e = edges[idx];
        adj[e.u].push_back({e.v, idx});
        adj[e.v].push_back({e.u, idx});

        in[idx] = true;
    }

    dfs();
    dsu = DSU(N);
    dsu.init();

    for(int i = 1; i <= E; ++i){
        if(!in[i]){
            Edge& e = edges[i];
            add_path(e.u, e.v);
            if(e.w == -1) e.w = ++Counter;
        }
        else if(edges[i].w == -1) edges[i].w = ++Counter;
    }

    for(int i = 1; i <= E; ++i){
        cout << edges[i].w << " ";
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> E;

    edges.emplace_back();
    for(int i = 1; i <= E; ++i){
        int a, b;
        cin >> a >> b;

        edges.push_back({a, b, i, -1});
    }

    Solve::solve();

    return 0;
}
