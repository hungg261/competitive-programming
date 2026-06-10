/******************************************************************************
Link: https://vjudge.net/contest/737964#problem/E
Code: E
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-17-08.01.32
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200000, MAXK = __lg(MAXN) + 1;
int h[MAXN + 5],
    table[MAXN + 5][MAXK + 5];

int n;
vector<int> adj[MAXN + 5];
vector<vector<int>> groups;

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
    int k;
    cin >> n >> k;
    groups.resize(k + 1);

    for(int i = 1; i <= n; ++i){
        int g, par;
        cin >> g >> par;

        table[i][0] = par;
        adj[par].push_back(i);

        groups[g].push_back(i);
    }

    dfs(0, -1);
    compute();

    for(int g = 1; g <= k; ++g){
        int best = 0, best_idx = 0;
        for(int u: groups[g]){
            int newdist = dist(u, groups[g][0]);
            if(newdist > best){
                best = newdist;
                best_idx = u;
            }
        }

        for(int u: groups[g]){
            int newdist = dist(u, best_idx);
            best = max(best, newdist);
        }

        cout << best << '\n';
    }

    return 0;
}
