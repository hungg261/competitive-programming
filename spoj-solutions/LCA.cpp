/******************************************************************************
Link: https://vjudge.net/contest/737964#problem/A
Code: A
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-08-16.19.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000, MAXK = __lg(MAXN) + 1;
int h[MAXN + 5], table[MAXN + 5][MAXK + 5];
vector<int> adj[MAXN + 5];
int n;

void dfs(int u, int prev){
    for(int v: adj[u]){
        if(v == prev) continue;

        h[v] = h[u] + 1;
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

int jump(int pos, int steps){
    for(int bit = 0; bit <= MAXK; ++bit){
        if(steps >> bit & 1){
            pos = table[pos][bit];
        }
    }

    return pos;
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    v = jump(v, h[v] - h[u]);

    if(u == v) return u;

    for(int bit = MAXK; bit >= 0; --bit){
        if(table[u][bit] != table[v][bit]){
            u = table[u][bit];
            v = table[v][bit];
        }
    }

    return table[u][0];
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i) table[i][0] = 0;
    for(int i = 1; i <= n; ++i){
        adj[i].clear();

        int m; cin >> m;
        for(int j = 1; j <= m; ++j){
            int child; cin >> child;
            table[child][0] = i;

            adj[i].push_back(child);
            adj[child].push_back(i);
        }
    }

    dfs(1, 0);
    compute();

    int q;
    cin >> q;

    while(q--){
        int u, v;
        cin >> u >> v;

        cout << find_lca(u, v) << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);

    int t;
    cin >> t;

    for(int test = 1; test <= t; ++test){
        cout << "Case " << test << ":\n";
        solve();
    }

    return 0;
}
