/******************************************************************************
Link: https://judge.yosupo.jp/problem/lca
Code: lca
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-11-14.42.38
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
int n, q;
vector<int> adj[MAXN + 5];

int h[MAXN + 5], par[MAXN + 5], sz[MAXN + 5];
void dfs(int u = 0, int prv = -1){
    sz[u] = 1;
    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int head[MAXN + 5], Pos[MAXN + 5], curChain = 0, curPos = 0;
void HLD(int u = 0, int prv = -1, int hd = 0){
    if(!head[u]) head[u] = hd;
    Pos[u] = ++curPos;

    int nxt = -1;
    for(int v: adj[u]){
        if(v == prv) continue;
        if(nxt == -1 || sz[v] > sz[nxt]) nxt = v;
    }

    if(nxt != -1) HLD(nxt, u, hd);

    for(int v: adj[u]){
        if(v == prv || v == nxt) continue;
        ++curChain;
        HLD(v, u, v);
    }
}

int find_lca(int u, int v){
    while(head[u] != head[v]){
        if(h[head[u]] > h[head[v]])
            u = par[head[u]];
        else v = par[head[v]];
    }

    if(h[u] > h[v]) swap(u, v);
    return u;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n - 1; ++i){
        int p; cin >> p;

        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    dfs();
    HLD();

    while(q--){
        int u, v;
        cin >> u >> v;

        cout << find_lca(u, v) << "\n";
    }

    return 0;
}
