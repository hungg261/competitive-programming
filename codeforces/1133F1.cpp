/******************************************************************************
Link: https://codeforces.com/contest/1133/problem/F1
Code: 1133F1
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-17-21.16.38
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
int n, m;
vector<int> adj[MAXN + 5];
int deg[MAXN + 5];



signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

        ++deg[a];
        ++deg[b];
    }

    vector<int> order(n);
    iota(begin(order), end(order), 1);

    sort(begin(order), end(order), [](int x, int y){
            return deg[x] > deg[y];
         });

    DSU dsu(n);
    dsu.init();
    for(int u: order){
        for(int v: adj[u]){
            if(dsu.unite(u, v)){
                cout << u << ' ' << v << '\n';
            }
        }
    }

    return 0;
}
