#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int h[MAXN + 5],
    sz[MAXN + 5],
    par[MAXN + 5],
    chainHead[MAXN + 5],
    chainID[MAXN + 5],
    pos[MAXN + 5],
    arr[MAXN + 5];
int curChain = 1, curPos;

vector<int> adj[MAXN + 5];
int n;

void dfs(int u, int prev){
    sz[u] = 1;

    for(int v: adj[u]){
        if(v == prev) continue;

        par[v] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void hld(int u, int prev){
    if(!chainHead[curChain]) chainHead[curChain] = u;
    chainID[u] = curChain;

    ++curPos;
    pos[u] = curPos;
    arr[curPos] = u;

    int nxt = 0;
    for(int v: adj[u]){
        if(v == prev) continue;

        if(nxt == 0 || sz[nxt] < sz[v]) nxt = v;
    }
    if(nxt != 0) hld(nxt, u);

    for(int v: adj[u]){
        if(v == prev || v == nxt) continue;
        ++curChain;
        hld(v, u);
    }
}

int find_lca(int u, int v){
    while(chainID[u] != chainID[v]){
        if(chainID[u] > chainID[v]) u = par[chainHead[chainID[u]]];
        else v = par[chainHead[chainID[v]]];
    }

    return h[u] < h[v] ? u : v;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 2; i <= n; ++i){
        int boss; cin >> boss;

        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }

    dfs(1, 0);
    hld(1, 0);

    while(q--){
        int u, v;
        cin >> u >> v;

        cout << find_lca(u, v) << '\n';
    }

    return 0;
}
