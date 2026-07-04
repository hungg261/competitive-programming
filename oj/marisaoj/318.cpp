/******************************************************************************
Link: https://marisaoj.com/problem/318
Code: 318
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-04-15.37.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int val[MAXN + 5];

struct DSU{
    int n;
    vector<int> par, sz;
    vector<vector<int>> state;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
        state.resize(n + 1);
    }

    void init(){
        for(int u = 0; u <= n; ++u)
            create(u);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
        state[v] = {v};
        val[v] = 0;
    }

    int find(int v){
        return par[v] == v ? v : par[v] = find(par[v]);
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }

    bool unite(int a, int b){
        bool lz = val[a] == val[b];
        a = find(a);
        b = find(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];

            for(int b_v: state[b]){
                state[a].push_back(b_v);
                if(lz) val[b_v] ^= 1;
            }

            return true;
        }

        return false;
    }
};

void solve(){

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;

    DSU dsu(n);
    dsu.init();

    while(q--){
        int type, u, v;
        cin >> type >> u >> v;

        if(type == 1){
            dsu.unite(u, v);
        }
        else{
            if(!dsu.same(u, v)) cout << "DUNNO\n";
            else if(val[u] != val[v]) cout << "FATAL\n";
            else cout << "SAFE\n";
        }
    }

    return 0;
}
