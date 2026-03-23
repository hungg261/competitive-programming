/******************************************************************************
Link: https://cses.fi/problemset/task/1136
Code: 1136
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-23-09.27.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXLG = __lg(MAXN) + 1;
int n, q;
int h[MAXN + 5], table[MAXN + 5][MAXLG + 5];
vector<int> adj[MAXN + 5];

void dfs(int u, int prv){
    for(int v: adj[u]){
        if(v == prv) continue;

        table[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i <= n; ++i){
            table[i][j] = table[table[i][j- 1]][j - 1];
        }
    }
}

int lift(int u, int s){
    for(int bit = MAXLG; bit >= 0; --bit){
        if(s >> bit & 1) u = table[u][bit];
    }
    return u;
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

int diff[MAXN + 5];
void propagate(int u, int prv){
    for(int v: adj[u]){
        if(v == prv) continue;

        propagate(v, u);
        diff[u] += diff[v];
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1136.INP","r",stdin);
    //freopen("1136.OUT","w",stdout);
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    compute();

    for(int i = 1; i <= q; ++i){
        int a, b;
        cin >> a >> b;

        int lca = find_lca(a, b);
        diff[a]++;
        diff[b]++;

        diff[lca]--;
        diff[table[lca][0]]--;
    }

    propagate(1, 0);
    for(int u = 1; u <= n; ++u){
        cout << diff[u] << ' ';
    }

    return 0;
}
