/******************************************************************************
Link: https://codeforces.com/contest/1624/problem/G
Code: 1624G
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-20-11.20.03
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
        for(int u = 1; u <= n; ++u)
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
            --n;

            return true;
        }

        return false;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        edges.emplace_back(a, b, c);
    }

    int res = 0;
    for(int b = 30; b >= 0; --b){
        DSU dsu(n);
        dsu.init();

        int allowed = ((1 << b) - 1) | res;
        for(const auto& e: edges){
            int u, v, w; tie(u, v, w) = e;
            if((w | allowed) == allowed){
                dsu.unite(u, v);
            }
        }

        if(dsu.n > 1) res |= 1 << b;
    }

    cout << res << "\n";
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
