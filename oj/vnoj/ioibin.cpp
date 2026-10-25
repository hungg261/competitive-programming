/******************************************************************************
Link: https://oj.vnoi.info/problem/ioibin
Code: ioibin
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-25-21.54.28
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

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> q;

    const int MAXN = 1e4;

    DSU dsu(MAXN + 5);
    dsu.init();

    while(q--){
        int X, Y, type;
        cin >> X >> Y >> type;

        if(type == 1) dsu.unite(X, Y);
        else{
            cout << dsu.same(X, Y) << "\n";
        }
    }

    return 0;
}
