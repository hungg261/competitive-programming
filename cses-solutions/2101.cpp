/******************************************************************************
Link: https://cses.fi/problemset/task/2101
Code: 2101
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-19-00.01.44
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz;

    DSU() = default;
    DSU(int _sz): n(_sz){ par.resize(n + 1); sz.resize(n + 1); init(); }

    void init(){
        for(int i = 0; i <= n; ++i){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_set(int v){
        return par[v] == v ? v : par[v] = find_set(par[v]);
    }

    bool same(int u, int v){
        return find_set(u) == find_set(v);
    }

    bool union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];

            return true;
        }

        return false;
    }
};

const int MAXN = 2e5, MAXM = 2e5, MAXQ = 2e5;
int n, m, q;
vector<pair<int, int>> edges;
vector<pair<int, int>> queries;

vector<int> candidates[MAXM + 5];
int L[MAXQ + 5], R[MAXQ + 5];

void solve(){
    for(int i = 1; i <= q; ++i) L[i] = 0, R[i] = m + 1;

    DSU dsu(n);
    while(true){
        bool changed = false;
        for(int i = 1; i <= q; ++i){
            if(L[i] < R[i]){
                int mid = (L[i] + R[i]) >> 1;
                candidates[mid].push_back(i);

                changed = true;
            }
        }
        if(!changed) break;

        for(int i = 0; i <= m; ++i){
            if(1 <= i && i <= m) dsu.union_sets(edges[i].first, edges[i].second);

            for(int cand: candidates[i]){
                int s, t;
                tie(s, t) = queries[cand];

                if(dsu.same(s, t)){
                    R[cand] = i;
                }
                else L[cand] = i + 1;
            }

            candidates[i].clear();
        }

        dsu.init();
    }

    for(int i = 1; i <= q; ++i){
        cout << (L[i] <= m ? L[i] : -1) << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;

    edges.emplace_back();
    queries.emplace_back();
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        edges.emplace_back(a, b);
    }
    for(int i = 1; i <= q; ++i){
        int a, b;
        cin >> a >> b;

        queries.emplace_back(a, b);
    }

    solve();

    return 0;
}
