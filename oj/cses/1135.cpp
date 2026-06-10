#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXK = __lg(MAXN) + 1;
int n, q;
vector<int> adj[MAXN + 5];
int par[MAXN + 5];

int table[MAXK + 5][MAXN + 5];
void compute(){
    for(int i = 1; i <= n; ++i){
        table[0][i] = par[i];
    }

    for(int k = 1; k <= MAXK; ++k){
        for(int i = 1; i <= n; ++i){
            table[k][i] = table[k - 1][table[k - 1][i]];
        }
    }
}

int jump(int pos, int steps){
    for(int bit = 0; bit <= 30; ++bit){
        if(steps >> bit & 1) pos = table[bit][pos];
    }
    return pos;
}

int h[MAXN + 5];
void dfs(int u, int prev){
    par[u] = u;

    for(int v: adj[u]){
        if(v == prev) continue;

        h[v] = h[u] + 1;
        dfs(v, u);
        par[v] = u;
    }
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    u = jump(u, h[u] - h[v]);

    if(u == v) return u;

    for(int k = __lg(h[u]); k >= 0; --k){
        if(table[k][u] != table[k][v]){
            u = table[k][u];
            v = table[k][v];
        }
    }

    return table[0][u];
}

int dist(int u, int v){
    return h[u] + h[v] - h[lca(u, v)] * 2;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    compute();

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << dist(a, b) << '\n';
    }

    return 0;
}
