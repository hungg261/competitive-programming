/******************************************************************************
Link: https://codeforces.com/problemset/problem/1833/E
Code: 1833E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-08-00.27.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> sz, par;

    DSU() = default;
    DSU(int _sz): n(_sz){
        sz.resize(n + 1);
        par.resize(n + 1);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
    }

    int find_set(int v){
        return par[v] == v ? v : find_set(par[v]);
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

void solve(){
    int n;
    cin >> n;

    vector<int> p(n + 1);
    DSU dsu(n);
    for(int i = 1; i <= n; ++i) dsu.create(i);

    for(int i = 1; i <= n; ++i){
        cin >> p[i];
        dsu.union_sets(i, p[i]);
    }

    set<int> mark;
    int sub = 0;
    for(int i = 1; i <= n; ++i){
        mark.insert(dsu.find_set(i));
        if(p[p[i]] == i){
            ++sub;
        }
    }
    sub /= 2;

    int sz = mark.size();
    cout << sz - max(0, sub - 1) << ' ' << sz << '\n';
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
