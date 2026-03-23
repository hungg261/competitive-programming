
/******************************************************************************
Link: https://atcoder.jp/contests/abc447/tasks/abc447_e
Code: abc447_e
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-28-19.32.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

int powmod(int a, int b, int m){
    int res = 1;
    a %= m;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

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

struct Edge{
    int u, v, w;

    bool operator < (const Edge& other) const{
        return w < other.w;
    }

    bool operator > (const Edge& other) const{
        return w > other.w;
    }
};
vector<Edge> edges;
int n, m;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        edges.push_back({a, b, powmod(2, i, MOD)});
    }

    reverse(begin(edges), end(edges));
    DSU dsu(n);
    dsu.init();

    int c = n;
    int res = 0;
    for(const Edge& e: edges){
        if(dsu.unite(e.u, e.v)){
            --c;
            if(c == 1) break;

            res = (res + e.w) % MOD;
        }
    }

    cerr << res << '\n';

    res = ((powmod(2, m + 1, MOD) - 2 + MOD) % MOD + MOD) % MOD;
    cout << res << '\n';

    return 0;
}
