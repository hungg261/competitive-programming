/******************************************************************************
Link: https://cses.fi/problemset/task/1687
Code: 1687
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-14-08.36.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXK = __lg(MAXN) + 1;
int h[MAXN + 5],
    table[MAXN + 5][MAXK + 5];

int n;
vector<int> adj[MAXN + 5];

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

int dist(int u, int v){
    return h[u] + h[v] - 2 * h[find_lca(u, v)];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1687.INP","r",stdin);
    //freopen("1687.OUT","w",stdout);
    int q;
    cin >> n >> q;
    for(int i = 2; i <= n; ++i){
        int boss;
        cin >> boss;

        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }

    dfs(1, 0);
    compute();

    while(q--){
        int x, k;
        cin >> x >> k;

        int res = lift(x, k);
        cout << (res == 0 ? -1 : res) << '\n';
    }

    return 0;
}
