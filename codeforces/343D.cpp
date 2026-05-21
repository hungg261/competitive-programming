/******************************************************************************
Link: https://codeforces.com/contest/343/problem/D
Code: 343D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-21-11.02.50
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
int n, q;
vector<int> adj[MAXN + 5];
int h[MAXN + 5], sz[MAXN + 5], par[MAXN + 5];

void dfs(int u, int prv){
    sz[u] = 1;
    for(int v: adj[u]){
        if(v == prv) continue;
        h[v] = h[u] + 1;
        par[v] = u;

        dfs(v, u);
        sz[u] += sz[v];
    }
}

int Head[MAXN + 5], ID[MAXN + 5];
int tin[MAXN + 5], tout[MAXN + 5], curChain = 1, curPos = 0;
void HLD(int u, int prv){
    if(!Head[curChain]) Head[curChain] = u;
    ID[u] = curChain;

    tin[u] = ++curPos;

    int nxt = -1;
    for(int v: adj[u]){
        if(v == prv) continue;
        if(nxt == -1 || sz[v] > sz[nxt]) nxt = v;
    }

    if(nxt != -1) HLD(nxt, u);
    for(int v: adj[u]){
        if(v == prv || v == nxt) continue;

        ++curChain;
        HLD(v, u);
    }

    tout[u] = curPos;
}

int nodes[MAXN * 4 + 5], lazy[MAXN * 4 + 5];

void apply(int id, int lz){
    nodes[id] = lz;
    lazy[id] = lz;
}

void push(int id){
    int &lz = lazy[id];
    if(lz == -1) return;

    apply(id << 1, lz);
    apply(id << 1 | 1, lz);

    lz = -1;
}

void assign(int id, int l, int r, int u, int v, int val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        apply(id, val);
        return;
    }

    push(id);

    int mid = (l + r) >> 1;
    assign(id << 1, l, mid, u, v, val);
    assign(id << 1 | 1, mid + 1, r, u, v, val);
}

int get(int id, int l, int r, int idx){
    if(l == r) return nodes[id];
    push(id);

    int mid = (l + r) >> 1;
    if(idx <= mid) return get(id << 1, l, mid, idx);
    else return get(id << 1 | 1, mid + 1, r, idx);
}

void update_path(int u, int v, int val){
    while(ID[u] != ID[v]){
        if(tin[u] > tin[v]){
            assign(1, 1, n, tin[Head[ID[u]]], tin[u], val);
            u = par[Head[ID[u]]];
        }
        else{
            assign(1, 1, n, tin[Head[ID[v]]], tin[v], val);
            v = par[Head[ID[v]]];
        }
    }

    if(h[u] > h[v]) swap(u, v);
    assign(1, 1, n, tin[u], tin[v], val);
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

    dfs(1, -1);
    HLD(1, -1);
    memset(lazy, -1, sizeof lazy);

    cin >> q;
    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int v; cin >> v;
            assign(1, 1, n, tin[v], tout[v], 1);
        }
        else if(type == 2){
            int v; cin >> v;
            update_path(1, v, 0);
        }
        else{
            int v; cin >> v;
            cout << get(1, 1, n, tin[v]) << "\n";
        }
    }

    return 0;
}
