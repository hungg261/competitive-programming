/******************************************************************************
Link: https://oj.uz/problem/view/NOI19_riggedroads
Code: NOI19_riggedroads
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-07-10.02.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5, MAXLG = __lg(MAXN) + 1;
int N, E;

struct EdgeTo{
    int v;
    int idx;
};
vector<EdgeTo> adj[MAXN + 5];

int h[MAXN + 5], table[MAXN + 5][MAXLG + 5];
pair<int, int> par[MAXN + 5];
struct Edge{
    int u, v;
    bool inTree;
    int idx;

    int w;
    void assign(int& _w){
        if(w > 0) return;
        w = ++_w;
    }
};
vector<Edge> edges;

void dfs(int u, int prv){
    for(int j = 1; j <= MAXLG; ++j)
        table[u][j] = table[table[u][j - 1]][j - 1];

    for(const EdgeTo& e: adj[u]){
        if(e.v == prv) continue;

        h[e.v] = h[u] + 1;
        table[e.v][0] = u;
        par[e.v] = {u, e.idx};

        dfs(e.v, u);
    }
}

namespace DSU{

int parent[MAXN + 5], sz[MAXN + 5], root[MAXN + 5];
void init(){
    for(int v = 0; v <= N; ++v){
        parent[v] = v;
        sz[v] = 1;
        root[v] = v;
    }
}

int find(int v){ return parent[v] == v ? v : parent[v] = find(parent[v]); }
bool same(int u, int v){ return find(u) == find(v); }

bool unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;

    if(sz[a] < sz[b]) swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
    if(h[root[b]] < h[root[a]]) root[a] = root[b];

    return true;
}

}

namespace Brute{

void solve(){
    vector<int> W(E + 1);
    iota(begin(W) + 1, end(W), 1);

    vector<int> res(E + 1);
    res[0] = 0; for(int i = 1; i <= E; ++i) res[i] = 1e9;

    do{
        vector<array<int, 3>> es;
        int Target = 0;
        for(int i = 1; i <= E; ++i){
            es.push_back({W[i], edges[i].u, edges[i].v});
            if(edges[i].inTree) Target += W[i];
        }

        sort(begin(es), end(es));
        int MST = 0;
        DSU::init();
        for(const array<int, 3>& e: es){
            if(DSU::unite(e[1], e[2])){
                MST += e[0];
            }
        }

        if(MST == Target) res = min(res, W);

    } while(next_permutation(begin(W) + 1, end(W)));

    for(int i = 1; i <= E; ++i) cout << res[i] << " "; cout << endl;
}

}

namespace Solve{

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

void solve(){
    dfs(1, -1);
    DSU::init();

    int tag = 0;
    for(int i = 1; i <= E; ++i){
        Edge& e = edges[i];
        if(e.inTree){
            e.assign(tag);
            DSU::unite(e.u, e.v);
        }
        else{
            if(h[e.u] > h[e.v]) swap(e.u, e.v);
            int u = e.u, v = e.v;
            int lca = find_lca(u, v);

            vector<int> idx;
            while(h[u] < h[v]){
                idx.push_back(par[v].second);

                DSU::unite(v, par[v].first);
                v = DSU::root[DSU::find(v)];
            }

            while(true){
                u = DSU::root[DSU::find(u)];
                v = DSU::root[DSU::find(v)];

                if(u == v) break;

                if(h[u] > h[lca]){
                    idx.push_back(par[u].second);
                    DSU::unite(u, par[u].first);
                }

                if(h[v] > h[lca]){
                    idx.push_back(par[v].second);
                    DSU::unite(v, par[v].first);
                }
            }

            sort(begin(idx), end(idx));
            for(int pos: idx) if(pos) edges[pos].assign(tag);
            edges[e.idx].assign(tag);
        }
    }

    for(int i = 1; i <= E; ++i) cout << edges[i].w << " "; cout << endl;
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> E;

    edges.emplace_back();
    for(int i = 1; i <= E; ++i){
        int a, b;
        cin >> a >> b;

        edges.push_back({a, b, false, i, 0});
    }

    for(int i = 1; i < N; ++i){
        int idx; cin >> idx;
        edges[idx].inTree = true;

        adj[edges[idx].u].push_back({edges[idx].v, idx});
        adj[edges[idx].v].push_back({edges[idx].u, idx});
    }

    Solve::solve();

    return 0;
}
