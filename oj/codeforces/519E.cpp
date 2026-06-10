/******************************************************************************
Link: https://codeforces.com/contest/519/problem/E
Code: 519E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-01-10.55.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXLG = __lg(MAXN) + 1;
int n, sz[MAXN + 5], h[MAXN + 5], table[MAXN + 5][MAXLG + 5];
vector<int> adj[MAXN + 5];

void dfs(int u, int prv){
    table[u][0] = prv;
    for(int j = 1; j <= MAXLG; ++j)
        table[u][j] = table[table[u][j - 1]][j - 1];

    h[u] = h[prv] + 1;
    sz[u] = 1;

    for(int v: adj[u]){
        if(v == prv) continue;

        dfs(v, u);
    }

    sz[prv] += sz[u];
}

int lift(int u, int s){
    for(int b = MAXLG; b >= 0; --b)
        if(s >> b & 1) u = table[u][b];

    return u;
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    v = lift(v, h[v] - h[u]);

    if(u == v) return u;

    for(int b = MAXLG; b >= 0; --b){
        if(table[u][b] != table[v][b]){
            u = table[u][b];
            v = table[v][b];
        }
    }

    return table[u][0];
}

int find_dist(int u, int v){
    return h[u] + h[v] - 2 * h[find_lca(u, v)];
}

void query(){
    int u, v;
    cin >> u >> v;

    if(u == v){
        cout << n << "\n";
        return;
    }

    int d = find_dist(u, v);
    if(d & 1){
        cout << "0\n";
        return;
    }

    int steps = d / 2;

    if(h[u] == h[v]){
        int a = lift(u, steps - 1);
        int b = lift(v, steps - 1);
        cout << n - sz[a] - sz[b] << "\n";
    }
    else{
        if(h[u] > h[v]) swap(u, v);

        int mid = lift(v, steps);
        int child_mid = lift(v, steps - 1);

        cout << sz[mid] - sz[child_mid] << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    int q;
    cin >> q;

    while(q--){
        query();
    }

    return 0;
}
