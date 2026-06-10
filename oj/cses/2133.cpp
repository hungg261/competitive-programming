/******************************************************************************
Link: https://cses.fi/problemset/task/2133
Code: 2133
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-23-22.49.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz;
    vector<int> history;
    int cc;

    DSU() = default;
    DSU(int _n): n(_n), cc(_n){
        par.resize(n + 1);
        sz.resize(n + 1);

        for(int u = 1; u <= n; ++u){
            par[u] = u;
            sz[u] = 1;
        }
    }

    int find(int v){
        return par[v] == v ? v : find(par[v]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){
            history.push_back(-1);
            return false;
        }

        if(sz[a] < sz[b]) swap(a, b);

        history.push_back(b);

        par[b] = a;
        sz[a] += sz[b];
        --cc;

        return true;
    }

    void rollback(){
        if(history.empty()) return;
        int b = history.back();
        history.pop_back();

        if(b == -1) return;

        int a = par[b];
        par[b] = b;
        sz[a] -= sz[b];
        ++cc;
    }
};

const int MAXN = 1e5, MAXM = 1e5, MAXK = 1e5;
int n, m, k;
map<pair<int, int>, int> mp;

vector<pair<int, int>> nodes[MAXK * 4 + 5];

void add_node(int id, int l, int r, int u, int v, pair<int, int> e){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        nodes[id].push_back(e);
        return;
    }

    int mid = (l + r) >> 1;
    add_node(id << 1, l, mid, u, v, e);
    add_node(id << 1 | 1, mid + 1, r, u, v, e);
}

int res[MAXK + 5];
DSU dsu;
void solve(int id, int l, int r){
    for(const pair<int, int>& e: nodes[id])
        dsu.unite(e.first, e.second);

    if(l == r) res[l] = dsu.cc;
    else{
        int mid = (l + r) >> 1;
        solve(id << 1, l, mid);
        solve(id << 1 | 1, mid + 1, r);
    }

    for(const pair<int, int>& e: nodes[id])
        (void)e, dsu.rollback();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    dsu = DSU(n);
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        if(a > b) swap(a, b);

        mp[{a, b}] = 0;
    }

    for(int i = 1; i <= k; ++i){
        int type, a, b;
        cin >> type >> a >> b;

        if(a > b) swap(a, b);

        pair<int, int> e = {a, b};
        if(type == 1) mp[e] = i;
        else{
            add_node(1, 0, k, mp[e], i - 1, e);
            mp.erase(e);
        }
    }
    for(const pair<pair<int, int>, int> e: mp){
        add_node(1, 0, k, e.second, k, e.first);
    }

    solve(1, 0, k);

    for(int i = 0; i <= k; ++i)
        cout << res[i] << " ";

    return 0;
}
