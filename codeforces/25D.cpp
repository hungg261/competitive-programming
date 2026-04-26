/******************************************************************************
Link: https://codeforces.com/contest/25/problem/D
Code: 25D
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-26-22.48.46
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

const int MAXN = 1000;
int n;
vector<pair<int, int>> candidates;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    DSU dsu(n);
    dsu.init();
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        if(!dsu.unite(a, b))
            candidates.emplace_back(a, b);
    }

    vector<int> head;
    for(int u = 1; u <= n; ++u)
        head.push_back(dsu.find(u));
    sort(begin(head), end(head));
    head.erase(unique(begin(head), end(head)), end(head));

    cout << (int)head.size() - 1 << endl;
    for(int i = 1; i < (int)head.size(); ++i){
        const pair<int, int>& e = candidates.back();
        cout << e.first << " " << e.second << " " << head[i - 1] << " " << head[i] << "\n";

        candidates.pop_back();
    }

    return 0;
}
