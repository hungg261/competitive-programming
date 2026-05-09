/******************************************************************************
Link: https://codeforces.com/contest/1245/problem/D
Code: 1245D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-08-09.42.30
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

    bool operator < (const Edge& other) const{
        return this->w < other.w;
    }
};

int n;
vector<Edge> edges;

pair<long long, vector<pair<int, int>>> kruskal(){
    sort(begin(edges), end(edges));
    vector<pair<int, int>> chosen;
    long long mst = 0;

    DSU dsu(n);
    dsu.init();

    for(const Edge& e: edges){
        if(dsu.unite(e.u, e.v)){
            mst += e.w;
            chosen.emplace_back(e.u, e.v);
        }
    }

    return {mst, chosen};
}

const int MAXN = 2000;
int x[MAXN + 5], y[MAXN + 5];
int c[MAXN + 5], k[MAXN + 5];

int mdist(int i, int j){
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];

    for(int i = 1; i <= n; ++i) cin >> c[i];
    for(int i = 1; i <= n; ++i) cin >> k[i];

    for(int i = 1; i <= n; ++i){
        edges.push_back({0, i, c[i]});
        for(int j = i + 1; j <= n; ++j){
            edges.push_back({i, j, (k[i] + k[j]) * mdist(i, j)});
        }
    }

    int cost;
    vector<pair<int, int>> built;
    tie(cost, built) = kruskal();

    vector<int> built_pos;
    for(const pair<int, int>& e: built)
        if(e.first == 0) built_pos.push_back(e.second);

    cout << cost << "\n";

    cout << built_pos.size() << "\n";
    for(int u: built_pos) cout << u << " ";
    cout << "\n";

    cout << built.size() - built_pos.size() << "\n";
    for(const pair<int, int>& e: built)
        if(e.first != 0) cout << e.first << " " << e.second << "\n";

    return 0;
}
