/******************************************************************************
Link: https://codeforces.com/contest/1133/problem/F2
Code: 1133F2
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-17-21.51.42
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

const int MAXN = 2e5;
int n, m, D;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> D;

    vector<int> to1;
    vector<pair<int, int>> normal;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        if(a > b) swap(a, b);

        if(a == 1){
            to1.push_back(b);
        }
        else normal.emplace_back(a, b);
    }

    if(D > (int)to1.size()){
        cout << "NO\n";
        return 0;
    }

    DSU checkComp(n);
    checkComp.init();

    for(const pair<int, int>& e: normal){
        checkComp.unite(e.first, e.second);
    }

    DSU dsu(n);
    dsu.init();
    vector<bool> mark(n + 1, false);
    vector<pair<int, int>> res;
    for(int i = 0; i < (int)to1.size(); ++i){
        int v = to1[i];
        if(checkComp.unite(1, v)){
            res.emplace_back(1, v);
            dsu.unite(1, v);
            mark[i] = true;
            --D;

            if(D == 0) break;
            else if(D < 0){
                cout << "NO\n";
                return 0;
            }
        }
    }

    if(D > 0) for(int i = 0; i < (int)to1.size(); ++i){
        if(mark[i]) continue;

        int v = to1[i];
        if(dsu.unite(1, v)){
            res.emplace_back(1, v);
            --D;
        }

        if(D <= 0) break;
    }

    for(const pair<int, int>& e: normal){
        if(dsu.unite(e.first, e.second)){
            res.push_back(e);
        }
    }

    if(D > 0 || (int)res.size() != n - 1) cout << "NO\n";
    else{
        cout << "YES\n";
        for(const pair<int, int>& e: res){
            cout << e.first << ' ' << e.second << '\n';
        }
    }

    return 0;
}
