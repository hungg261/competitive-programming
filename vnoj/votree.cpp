/******************************************************************************
Link: https://vjudge.net/contest/737964#problem/G
Code: G
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-17-22.44.26
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXK = __lg(MAXN) + 1;
int h[MAXN + 5],
    table[MAXN + 5][MAXK + 5];

int n;
vector<int> adj[MAXN + 5];
int lca_st[MAXN + 5][MAXK + 5];

void dfs(int u, int prev){
    for(int v: adj[u]){
        if(v == prev) continue;

        h[v] = h[u] + 1;
        table[v][0] = u;
        dfs(v, u);
    }
}

void compute(){
    for(int k = 1; k <= MAXK; ++k){
        for(int i = 1; i <= n; ++i){
            table[i][k] = table[table[i][k - 1]][k - 1];
        }
    }
}

int lift(int pos, int steps){
    for(int bit = MAXK; bit >= 0; --bit){
        if(steps >> bit & 1) pos = table[pos][bit];
    }
    return pos;
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    v = lift(v, h[v] - h[u]);

    if(u == v) return u;

    for(int bit = MAXK; bit >= 0; --bit){
        if(table[u][bit] != table[v][bit]){
            u = table[u][bit];
            v = table[v][bit];
        }
    }

    return table[u][0];
}

int find_lca_range(int l, int r){
    int bit = __lg(r - l + 1);
    return find_lca(lca_st[l][bit], lca_st[r - (1 << bit) + 1][bit]);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("G.INP","r",stdin);
    //freopen("G.OUT","w",stdout);

    int q;
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    compute();
    for(int i = 1; i <= n; ++i) lca_st[i][0] = i;
    for(int k = 1; k <= MAXK; ++k){
        for(int i = 1; i + (1 << k) - 1 <= n; ++i){
            lca_st[i][k] = find_lca(lca_st[i][k - 1], lca_st[i + (1 << (k - 1))][k - 1]);
        }
    }

    // cin >> q;

    while(q--){
        int u, v;
        cin >> u >> v;

        cout << find_lca_range(u, v) << '\n';
    }

    return 0;
}
