/******************************************************************************
Link: https://marisaoj.com/problem/511
Code: 511
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-04-15.22.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<long long> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    inline void update(int idx, long long val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    inline long long get(int idx){
        if(idx <= 0) return 0;

        long long res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    long long get(int l, int r){ return get(r) - get(l - 1); }
};

FenwickTree fwtA, fwtB;
void range_update(int l, int r, int x){
    fwtA.update(l, x);
    fwtA.update(r + 1, -x);

    fwtB.update(l, 1LL * x * (l - 1));
    fwtB.update(r + 1, -1LL * x * r);
}

long long get(int r){
    return r * fwtA.get(r) - fwtB.get(r);
}
long long get(int l, int r){ return get(r) - get(l - 1); }

const int MAXN = 2e5;

int n, q;
int h[MAXN + 5], sz[MAXN + 5], par[MAXN + 5];
int ChainID[MAXN + 5], ChainHead[MAXN + 5],
    Pos[MAXN + 5],
    curChain = 1, curPos = 0;
vector<int> adj[MAXN + 5];

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

void Hld(int u, int prv){
    if(!ChainHead[curChain]) ChainHead[curChain] = u;
    ChainID[u] = curChain;

    Pos[u] = ++curPos;

    int nxt = -1;
    for(int v: adj[u]){
        if(v == prv) continue;
        if(nxt == -1 || sz[v] > sz[nxt]) nxt = v;
    }
    if(nxt != -1) Hld(nxt, u);

    for(int v: adj[u]){
        if(v == prv || v == nxt) continue;

        ++curChain;
        Hld(v, u);
    }
}

void add_subtree(int u, int x){
    range_update(Pos[u], Pos[u] + sz[u] - 1, x);
}

void add_node(int u, int x){
    range_update(Pos[u], Pos[u], x);
}

long long query(int u, int v){
    long long res = 0;
    while(ChainID[u] != ChainID[v]){
        if(h[ChainHead[ChainID[u]]] > h[ChainHead[ChainID[v]]]) swap(u, v);

        res += get(Pos[ChainHead[ChainID[v]]], Pos[v]);
        v = par[ChainHead[ChainID[v]]];
    }

    if(h[u] > h[v]) swap(u, v);
    res += get(Pos[u], Pos[v]);

    return res;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    Hld(1, 0);

    fwtA = FenwickTree(n + 1);
    fwtB = FenwickTree(n + 1);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int u, x;
            cin >> u >> x;

            add_subtree(u, x);
        }
        else if(type == 2){
            int u, x;
            cin >> u >> x;

            add_node(u, x);
        }
        else{
            int u, v;
            cin >> u >> v;

            cout << query(u, v) << '\n';
        }
    }

	return 0;
}
