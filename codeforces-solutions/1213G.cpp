/******************************************************************************
Link: https://codeforces.com/contest/1213/problem/G
Code: 1213G
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-14-15.29.40
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

    Edge() = default;
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w){}

    bool operator < (const Edge& other) const{
        return w < other.w;
    }
};

struct Query{
    int qi, idx;

    void input(int i){
        cin >> qi;
        idx = i;
    }

    bool operator < (const Query& other) const{
        return qi < other.qi;
    }
};

const int MAXN = 2e5;
int n, q;
vector<Edge> edges;
vector<Query> queries;

int nC2(int x){
    return x * (x - 1) / 2;
}

void solve(){
    DSU dsu(n);
    dsu.init();

    int curRes = 0;
    int eidx = 0;
    vector<int> res(q);
    for(int i = 0; i < q; ++i){
        while(eidx < n - 1 && edges[eidx].w <= queries[i].qi){
            int u = edges[eidx].u, v = edges[eidx].v;
            int ui = dsu.find(u), vi = dsu.find(v);

            if(ui != vi){
                curRes -= nC2(dsu.sz[ui]);
                curRes -= nC2(dsu.sz[vi]);
                dsu.unite(u, v);

                curRes += nC2(dsu.sz[dsu.find(u)]);
            }

            ++eidx;
        }

        res[queries[i].idx] = curRes;
    }

    for(int i = 0; i < q; ++i){
        cout << res[i] << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        edges.emplace_back(a, b, c);
    }
    queries.resize(q);
    for(int i = 0; i < q; ++i){
        queries[i].input(i);
    }

    sort(begin(edges), end(edges));
    sort(begin(queries), end(queries));

    solve();

    return 0;
}
