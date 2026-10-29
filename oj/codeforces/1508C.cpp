/******************************************************************************
Link: https://codeforces.com/contest/1508/problem/C
Code: 1508C
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-28-20.01.50
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct DSU{
    int n;
    vector<int> par, sz;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
        init();
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

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];

            return true;
        }

        return false;
    }
};

const int MAXN = 2e5;
int n, m, target_xor = 0;
vector<pair<int, int>> adj[MAXN + 5];
set<int> is_edge[MAXN + 5];

struct Edge{
    int u, v, w;
    bool operator < (const Edge &other) const {
        return w < other.w;
    }
}; vector<Edge> edges;

int kruskal(vector<Edge> edge_list){
    sort(begin(edge_list), end(edge_list));
    DSU dsu(n);
    int mst = 0;
    for(const Edge &e: edge_list){
        if(dsu.unite(e.u, e.v)){
            mst += e.w;
        }
    }
    return mst;
}

namespace Brute{ void solve(); }

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        target_xor ^= c;

        adj[a].push_back({c, b});
        adj[b].push_back({c, a});

        is_edge[a].insert(b);
        is_edge[b].insert(a);

        edges.push_back({a, b, c});
    }

    set<int> unvis;
    for(int u = 1; u <= n; ++u) unvis.insert(u);

    vector<int> in_cc(n + 1, false);
    bool if_cycle = false;

    vector<int> cc_id(n + 1);
    int cc_cnt = 0;
    DSU dsu_zero(n), dsu_real(n);

    for(int i = 1; i <= n; ++i){
        if(!unvis.count(i)) continue;

        queue<int> que;
        que.push(i);

        vector<int> component;
        ++cc_cnt;
        while(!que.empty()){
            int u = que.front(); que.pop();

            if(in_cc[u]) continue;
            component.push_back(u);
            in_cc[u] = true;
            cc_id[u] = cc_cnt;

            vector<int> erased;
            for(int v: unvis){
                if(is_edge[u].count(v)) continue;
                que.push(v);
                erased.push_back(v);
                dsu_zero.unite(u, v);
            }

            for(int v: erased) unvis.erase(v);
        }

        int V = component.size();
        int E = V * (V - 1) / 2;
        for(int u: component){
            for(const pair<int, int> &e: adj[u]){
                int v, w; tie(w, v) = e;
                if(u < v && in_cc[v]){
                    --E;
                }
            }
        }

        for(int u: component){
            in_cc[u] = false;
        }

        if(E != V - 1){
            if_cycle = true;
        }
    }

    sort(begin(edges), end(edges));

    int mst = 0;
    for(const Edge &e: edges){
        if(dsu_zero.same(e.u, e.v)){
            if(!if_cycle && !dsu_real.same(e.u, e.v)){
                target_xor = min(target_xor, e.w);
            }
        }
        else if(dsu_real.unite(e.u, e.v)){
            dsu_zero.unite(e.u, e.v);
            mst += e.w;
        }
    }

    if(!if_cycle) mst += target_xor;

    cout << mst << "\n";

    return 0;
}

namespace Brute{

void solve(){
    for(int u = 1; u <= n; ++u){
        for(int v = u + 1; v <= n; ++v){
            if(!is_edge[u].count(v)){
                edges.push_back({u, v, 0});
            }
        }
    }

    int res = LLONG_MAX / 2;
    for(Edge &e: edges){
        if(e.w != 0) continue;
        int old = e.w;
        e.w = target_xor;
        res = min(res, kruskal(edges));
        e.w = old;
    }

    cout << res << "\n";
}

}
