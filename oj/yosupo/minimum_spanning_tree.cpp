/******************************************************************************
Link: https://judge.yosupo.jp/problem/minimum_spanning_tree
Code: minimum_spanning_tree
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-13-09.54.31
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct DSU{
    int n;
    vector<int> par, sz;

    DSU(int _n): n(_n){
        par.resize(n + 1);
        sz.resize(n + 1);
        init();
    }

    void init(){
        for(int u = 0; u <= n; ++u){
            par[u] = u;
            sz[u] = 1;
        }
    }

    int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
    bool same(int u, int v) { return find(u) == find(v); }
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

const int MAXN = 5e5;
int n, m;
struct Edge{
    int u, v, w, id;

    void input(int i){
        cin >> u >> v >> w;
        id = i;
    }

    bool operator < (const Edge& other) const {
        return w < other.w;
    }
};
vector<Edge> edges;

void getmst(){
    sort(begin(edges), end(edges));
    vector<int> chosen; int mst = 0;
    DSU dsu(n);
    for(const Edge& e: edges){
        if(dsu.unite(e.u, e.v)){
            mst += e.w;
            chosen.push_back(e.id);
        }
    }

    cout << mst << "\n";
    for(int x: chosen) cout << x << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        Edge cur; cur.input(i);
        edges.push_back(cur);
    }

    getmst();

    return 0;
}
