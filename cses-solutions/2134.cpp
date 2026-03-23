/******************************************************************************
Link: https://cses.fi/problemset/task/2134
Code: 2134
Time (YYYY-MM-DD-hh.mm.ss): 2025-09-26-17.55.02
*******************************************************************************/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int MAXN = 2e5;
int h[MAXN + 5],
    sz[MAXN + 5],
    par[MAXN + 5],

    ChainHead[MAXN + 5],
    ChainID[MAXN + 5],
    Arr[MAXN + 5],
    Pos[MAXN + 5],
    curChain = 1, curPos;

vector<int> adj[MAXN + 5];
int n, v[MAXN + 5];

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
    if(!ChainHead[curChain]) ChainHead[curChain] = u;
    ChainID[u] = curChain;

    ++curPos;
    Arr[curPos] = u;
    Pos[u] = curPos;

    int nxt = 0;
    for(int v: adj[u]){
        if(v == prev) continue;

        if(nxt == 0 || sz[nxt] < sz[v]) nxt = v;
    }
    if(nxt) hld(nxt, u);

    for(int v: adj[u]){
        if(v == prev || v == nxt) continue;

        ++curChain;
        hld(v, u);
    }
}

int nodes[MAXN * 2 + 5];
void build(){
    for(int i = 0; i < n; ++i){
        nodes[i + n] = v[Arr[i + 1]];
    }

    for(int id = n - 1; id > 0; --id){
        nodes[id] = max(nodes[id << 1], nodes[id << 1 | 1]);
    }
}

void update(int id, int val){
    --id;
    id += n;
    nodes[id] = val;

    while(id > 1){
        id >>= 1;
        nodes[id] = max(nodes[id << 1], nodes[id << 1 | 1]);
    }
}

int get(int l, int r){
    --l;
    l += n; r += n;

    int res = -1e9;
    while(l < r){
        if(l & 1) res = max(res, nodes[l++]);
        if(r & 1) res = max(res, nodes[--r]);
        l >>= 1; r >>= 1;
    }

    return res;
}

int maxquery(int u, int v){
    int res = -1e9;
    while(ChainID[u] != ChainID[v]){
        if(ChainID[u] > ChainID[v]){
            res = max(res, get(Pos[ChainHead[ChainID[u]]], Pos[u]));
            u = par[ChainHead[ChainID[u]]];
        }
        else{
            res = max(res, get(Pos[ChainHead[ChainID[v]]], Pos[v]));
            v = par[ChainHead[ChainID[v]]];
        }
    }
    if(h[u] > h[v]) swap(u, v);
    res = max(res, get(Pos[u], Pos[v]));

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }

    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    hld(1, 0);
    build();

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int s, x;
            cin >> s >> x;

            update(Pos[s], x);
        }
        else{
            int u, v;
            cin >> u >> v;

            cout << maxquery(u, v) << ' ';
        }
    }

    return 0;
}
