/******************************************************************************
Link: https://codeforces.com/problemset/problem/342/E
Code: 342E
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-02-18.19.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n;
vector<int> adj[MAXN + 5];

namespace CentroidDecomposition{

bool removed[MAXN + 5];
int centroidPar[MAXN + 5];
int Sz[MAXN + 5];

int getSubtreeSz(int u, int par){
    Sz[u] = 1;
    for(int v: adj[u]){
        if(v == par || removed[v]) continue;
        Sz[u] += getSubtreeSz(v, u);
    }
    return Sz[u];
}

int findCentroid(int u, int par, int total){
    for(int v: adj[u]){
        if(v == par || removed[v]) continue;

        if(Sz[v] > total / 2)
            return findCentroid(v, u, total);
    }
    return u;
}

void decompose(int u, int par){
    int totalSz = getSubtreeSz(u, -1);
    int centroid = findCentroid(u, -1, totalSz);

    centroidPar[centroid] = par;
    removed[centroid] = true;

    for(int v: adj[centroid]){
        if(removed[v]) continue;

        decompose(v, centroid);
    }
}

}

namespace LCA{

const int MAXLG = __lg(MAXN);
int h[MAXN + 5], table[MAXN + 5][MAXLG + 5];

void dfs(int u, int par){
    for(int v: adj[u]){
        if(v == par) continue;

        h[v] = h[u] + 1;
        table[v][0] = u;

        dfs(v, u);
    }
}

void compute(){
    dfs(1, -1);
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i <= n; ++i){
            table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    {
        int diff = h[v] - h[u];
        for(int b = MAXLG; b >= 0; --b)
            if(diff >> b & 1) v = table[v][b];
    }

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
    return h[u] + h[v] - h[find_lca(u, v)] * 2;
}

}

using namespace CentroidDecomposition;
using namespace LCA;

int res[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    decompose(1, -1);
    compute();
    memset(res, 0x3f, sizeof res);

    auto update = [&](int u){
        int c = u;
        while(c != -1){
            res[c] = min(res[c], find_dist(c, u));
            c = centroidPar[c];
        }
    };

    auto get = [&](int u){
        int ans = INT_MAX;
        int c = u;
        while(c != -1){
            ans = min(ans, res[c] + find_dist(c, u));
            c = centroidPar[c];
        }
        return ans;
    };

    update(1);
    while(q--){
        int type, x;
        cin >> type >> x;

        if(type == 1){
            update(x);
        }
        else{
            cout << get(x) << '\n';
        }
    }

    return 0;
}
