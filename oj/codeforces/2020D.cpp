/******************************************************************************
Link: https://codeforces.com/contest/2020/problem/D
Code: 2020D
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-16-18.37.02
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

void solve(){
    int n, m;
    cin >> n >> m;

    vector<array<int, 11>> St(n + 1), En(n + 1);
    vector<array<int, 11>> dp(n + 1);
    DSU dsu(n);
    dsu.init();

    for(int i = 1; i <= m; ++i){
        int a, d, k;
        cin >> a >> d >> k;

        ++St[a][d];
        ++En[a + k * d][d];
    }

    int component = n;
    for(int i = 1; i <= n; ++i){
        for(int w = 1; w <= 10; ++w){
            dp[i][w] = St[i][w] - En[i][w];
            if(i - w > 0 && dp[i - w][w] > 0){
                if(dsu.unite(i - w, i)) --component;
                dp[i][w] += dp[i - w][w];
            }
        }
    }

    cout << component << '\n';
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
