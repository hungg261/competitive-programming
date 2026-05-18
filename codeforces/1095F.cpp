/******************************************************************************
Link: https://codeforces.com/contest/1095/problem/F
Code: 1095F
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-18-20.28.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, m;
long long a[MAXN + 5];
vector<pair<int, int>> adj[MAXN + 5];

struct DSU{
    int n;
    vector<int> par, sz;
    vector<long long> minVal;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
        minVal.resize(n + 1);
    }

    void init(){
        for(int u = 0; u <= n; ++u)
            create(u);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
        minVal[v] = a[v];
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
            minVal[a] = min(minVal[a], minVal[b]);

            return true;
        }

        return false;
    }
};

struct ExtraEdge{
    int u, v;
    long long w;
};

struct BestEdge{
    int u = -1 , v = -1;
    long long w = LLONG_MAX;
};

vector<ExtraEdge> extra;

long long Boruvka(){
    int components = n;
    DSU dsu(n);
    dsu.init();

    long long mst = 0;
    while(components > 1){
        vector<BestEdge> best_edges(n + 1);

        pair<int, int> two_best = {-1, -1};
        for(int u = 1; u <= n; ++u){
            if(dsu.find(u) == u){
                if(two_best.first == -1 || dsu.minVal[u] <= dsu.minVal[two_best.first]){
                    two_best.second = two_best.first;
                    two_best.first = u;
                }
                else if(two_best.second == -1 || dsu.minVal[u] < dsu.minVal[two_best.second])
                    two_best.second = u;
            }
        }

        for(int u = 1; u <= n; ++u){
            if(dsu.find(u) == u){
                int target = u == two_best.first ? two_best.second : two_best.first;

                if(target != -1){
                    best_edges[u].u = u;
                    best_edges[u].v = target;
                    best_edges[u].w = dsu.minVal[u] + dsu.minVal[target];
                }
            }
        }

        for(const ExtraEdge& e: extra){
            int a = dsu.find(e.u), b = dsu.find(e.v);
            if(a == b) continue;

            if(e.w < best_edges[a].w){
                best_edges[a].u = e.u;
                best_edges[a].v = e.v;
                best_edges[a].w = e.w;
            }
            if(e.w < best_edges[b].w){
                best_edges[b].u = e.u;
                best_edges[b].v = e.v;
                best_edges[b].w = e.w;
            }
        }

        bool united = false;
        for(int u = 1; u <= n; ++u){
            if(dsu.find(u) != u) continue;

            const BestEdge& e = best_edges[u];
            if(e.v == -1) continue;

            if(dsu.unite(e.u, e.v)){
                mst += e.w;
                --components;

                united = true;
            }
        }

        if(!united) break;
    }

    return mst;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i){
        int a, b; long long c;
        cin >> a >> b >> c;

        extra.push_back({a, b, c});
    }

    cout << Boruvka() << "\n";

    return 0;
}
