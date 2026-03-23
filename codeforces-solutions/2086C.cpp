#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz;

    DSU() = default;
    DSU(int _sz): n(_sz + 1){
        par.resize(_sz + 1);
        sz.resize(_sz + 1);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
    }

    int find_set(int v){
        return par[v] == v ? v : par[v] = find_set(par[v]);
    }

    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];
        }
    }
};

void solve(){
    int n;
    cin >> n;

    vector<int> p(n + 1), d(n + 1);
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i) cin >> d[i];

    DSU dsu(n);
    for(int i = 1; i <= n; ++i) dsu.create(i);

    for(int i = 1; i <= n; ++i){
        dsu.union_sets(p[i], i);
    }

    set<int> mark;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int id = dsu.find_set(p[d[i]]);
        if(!mark.count(id)){
            ans += dsu.sz[id];
            mark.insert(id);
        }

        cout << ans << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}
