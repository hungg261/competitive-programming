/******************************************************************************
Link: https://marisaoj.com/problem/276
Code: 276
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-06-16.55.38
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n, a[MAXN + 5], mx[MAXN + 5];
vector<int> adj[MAXN + 5];

void dfs_compute(int u = 1, int prv = -1){
    mx[u] = a[u];
    for(int v: adj[u]){
        if(v == prv) continue;
        dfs_compute(v, u);

        mx[u] = max(mx[u], mx[v]);
    }
}

int distinct[MAXN + 5];
set<int> dfs_distinct(int u, int prv){
    set<int> S;
    for(int v: adj[u]){
        if(v == prv) continue;

        set<int> child = dfs_distinct(v, u);
        if(child.size() > S.size()) swap(S, child);

        for(int x: child) S.insert(x);
    }

    distinct[u] = S.size();
    return S;
}

namespace Solve{

int res;
map<int, int> dfs(int u = 1, int prv = -1){
    int nxt = -1;
    for(int v: adj[u]){
        if(v == prv) continue;
        if(nxt == -1 || distinct[v] > distinct[nxt]) nxt = v;
    }


    map<int, int> f;
    if(nxt != -1) f = dfs(nxt, u);
    f[a[u]] = max(f[a[u]], 1);

    for(int v: adj[u]){
        if(v == prv || v == nxt) continue;

        map<int, int> fs = dfs(v, u);

        for(const pair<int, int>& p: fs){

        }
    }
}

void solve(){
    dfs();
    cout << res << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    vector<int> values;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        values.push_back(a[i]);
    }
    sort(begin(values), end(values));
    for(int i = 1; i <= n; ++i)
        a[i] = lower_bound(begin(values), end(values), a[i]) - begin(values) + 1;

    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_compute();
    Solve::solve();

    return 0;
}
