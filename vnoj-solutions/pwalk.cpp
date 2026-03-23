/******************************************************************************
Link: https://oj.vnoi.info/problem/pwalk
Code: pwalk
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-23-18.51.17
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1000, MAXLG = __lg(MAXN) + 1;
int n, q;
vector<pair<int, int>> adj[MAXN + 5];

int h[MAXN + 5], g[MAXN + 5], table[MAXN + 5][MAXLG + 5];

void dfs(int u, int prv){
    for(const pair<int, int>& e: adj[u]){
        int v, w; tie(v, w) = e;
        if(v == prv) continue;

        h[v] = h[u] + 1;
        g[v] = g[u] + w;
        table[v][0] = u;
        dfs(v, u);
    }
}

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i <= n; ++i){
            table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
}

int lift(int u, int s){
    for(int b = MAXLG; b >= 0; --b){
        if(s >> b & 1){
            u = table[u][b];
        }
    }
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
    return g[u] + g[v] - 2 * g[find_lca(u, v)];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    dfs(1, 0);
    compute();

    while(q--){
        int u, v;
        cin >> u >> v;

        cout << find_dist(u, v) << '\n';
    }


    return 0;
}
