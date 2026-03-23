/******************************************************************************
Link: https://oj.vnoi.info/problem/kbuild
Code: kbuild
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-21-01.20.57
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXLG = __lg(MAXN) + 1;
int n, h[MAXN + 5], table[MAXN + 5][MAXLG + 5];
vector<int> adj[MAXN + 5];

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i <= n; ++i){
            table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
}

void dfs(int u, int prv){
    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        table[v][0] = u;
        dfs(v, u);
    }
}

int lift(int pos, int steps){
    for(int bit = MAXLG; bit >= 0; --bit){
        if(steps >> bit & 1){
            pos = table[pos][bit];
        }
    }

    return pos;
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    v = lift(v, h[v] - h[u]);

    if(u == v) return u;

    for(int bit = MAXLG; bit >= 0; --bit){
        if(table[u][bit] != table[v][bit]){
            u = table[u][bit];
            v = table[v][bit];
        }
    }

    return table[u][0];
}

int find_dist(int u, int v){
    return h[u] + h[v] - 2 * h[find_lca(u, v)];
}

int diff[MAXN + 5];
void propagate(int u, int prv){
    for(int v: adj[u]){
        if(v == prv) continue;

        propagate(v, u);
        diff[u] += diff[v];
    }
}

void inc(int u, int v, int x){
    diff[u] += x;
    diff[v] += x;

    int lca = find_lca(u, v);
    diff[lca] -= x;
    diff[table[lca][0]] -= x;
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
    compute();

    int q;
    cin >> q;

    while(q--){
        int u, v;
        cin >> u >> v;

        int lca = find_lca(u, v);
        if(u != lca){
            int du = find_dist(u, lca);
            int uu = lift(u, du - 1);
            inc(u, uu, 1);
        }
        if(v != lca){
            int dv = find_dist(v, lca);
            int vv = lift(v, dv - 1);
            inc(v, vv, 1);
        }
    }

    propagate(1, 0);

    int res = 0;
    for(int i = 2; i <= n; ++i){

        if(diff[i] == 0){
            ++res;
        }
    }

    cout << res << '\n';

    return 0;
}
