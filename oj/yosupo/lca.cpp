/******************************************************************************
Link: https://judge.yosupo.jp/problem/lca
Code: lca
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-11-08.18.41
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5, MAXLG = __lg(MAXN) + 1;
int n, q, table[MAXN + 5][MAXLG + 5], h[MAXN + 5];
vector<int> adj[MAXN + 5];

void dfs(int u = 0, int prv = -1){
    for(int j = 1; j <= MAXLG; ++j)
        table[u][j] = table[table[u][j - 1]][j - 1];

    for(int v: adj[u]){
        if(v == prv) continue;

        table[v][0] = u;
        h[v] = h[u] + 1;

        dfs(v, u);
    }
}

int lift(int v, int s){
    for(int b = MAXLG; b >= 0; --b)
        if(s >> b & 1) v = table[v][b];
    return v;
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

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n - 1; ++i){
        int p; cin >> p;

        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    dfs();

    while(q--){
        int u, v;
        cin >> u >> v;

        cout << find_lca(u, v) << "\n";
    }

    return 0;
}
