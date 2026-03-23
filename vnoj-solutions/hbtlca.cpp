/******************************************************************************
Link: https://vjudge.net/contest/737964#problem/F
Code: F
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-17-09.50.44
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000, MAXK = __lg(MAXN) + 1;
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
    //freopen("F.INP","r",stdin);
    //freopen("F.OUT","w",stdout);
    while(cin >> n, n){
        for(int i = 1; i <= n; ++i) adj[i].clear();
        for(int i = 1; i < n; ++i){
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int root = 1;
        dfs(root, 0);
        compute();

        int q;
        cin >> q;

        while(q--){
            char type;
            cin >> type;

            if(type == '!'){
                cin >> root;
            }
            else{
                int u, v;
                cin >> u >> v;

                cout << (find_lca(u, v) ^ find_lca(u, root) ^ find_lca(v, root)) << '\n';
            }
        }
    }

    return 0;
}
