/******************************************************************************
Link: https://codeforces.com/contest/2277/problem/C
Code: 2277C
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-24-19.00.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5, MAXQ = 5e5;
int n, m;
vector<int> adj[MAXN + 5];

int mark[MAXN + 5], dist[MAXN + 5], q[MAXN + 5];
int par[MAXN + 5], res[MAXN + 5];

void dfs_c(int u = 1, int prv = 0){
    par[u] = prv;
    for(int v: adj[u]){
        if(v == prv) continue;
        dfs_c(v, u);
    }
}

void dfs_dist(int u = n, int prv = -1){
    for(int v: adj[u]){
        if(v == prv) continue;
        dist[v] = dist[u] + 1;
        dfs_dist(v, u);
    }
}

bool dfs(int u = 1, int prv = -1){
    for(int v: adj[u]){
        if(v == prv) continue;
        if(dfs(v, u)){
            mark[u] = true;
            return true;
        }
    }
    return u == n;
}

void dfs2(int u, int root, int prv = -1){
    if(q[u]){
        int p = par[root];
        res[p] = max(res[p], dist[u] + 1);
    }
    for(int v: adj[u]){
        if(v == prv || mark[v]) continue;
        dfs2(v, root, u);
    }
}

void solve(){
    cin >> n >> m;
    for(int u = 1; u <= n; ++u){
        adj[u].clear();
        dist[u] = 0;
        q[u] = false;
        mark[u] = false;
        res[u] = 0;
    }

    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= m; ++i){
        int v;
        cin >> v;

        q[v] = true;
    }

    dfs();
    dfs_c();
    mark[n] = true;

    dfs_dist();
    res[1] = dist[1];

    for(int u = 1; u <= n; ++u){
        if(mark[u]){
            dfs2(u, u);
        }
    }

    int ans = 0;
    for(int u = 1; u <= n; ++u){
        if(mark[u]) ans = max(ans, res[u]);
//        cerr << res[u] << "/" << dist[u] << " ";
    }

    cout << ans << "\n";
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
