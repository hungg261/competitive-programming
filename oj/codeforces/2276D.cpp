/******************************************************************************
Link: https://codeforces.com/contest/2276/problem/D
Code: 2276D
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-14-22.29.11
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

            return true;
        }

        return false;
    }
};


bool dfs(vector<vector<int>> &adj, int u = 1, int prv = -1){
    for(int v: adj[u]){
        if(v == prv) continue;

        if((int)adj[u].size() > 1 && (int)adj[v].size() > 1){
            return true;
        }

        if(dfs(adj, v, u)) return true;
    }

    return false;
}


void solve(){
    int n, m;
    cin >> n >> m;

    DSU dsu(n); dsu.init();
    bool cycle = false;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        if(!dsu.unite(a, b)){
            cycle = true;
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cc = 0;
    for(int u = 1; u <= n; ++u){
        if(dsu.find(u) == u){
            ++cc;

            int fu = dsu.find(u);
            if(dsu.sz[fu] == 1){
                cout << "Brain Melt\n";
                return;
            }
        }
    }

    if(cc > 1 || cycle) cout << "Many\n";
    else{
        if(dfs(adj)) cout << "Many\n";
        else cout << "2\n";
    }
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
