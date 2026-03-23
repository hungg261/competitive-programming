/******************************************************************************
Link: https://marisaoj.com/problem/512
Code: 512
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-04-16.51.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<long long> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, long long val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    long long get(int idx){
        if(idx <= 0) return 0;

        long long res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

FenwickTree fwtA, fwtB;
void range_update(int l, int r, int x){
    fwtA.update(l, x);
    fwtA.update(r + 1, -x);

    fwtB.update(l, 1LL * x * (l - 1));
    fwtB.update(r + 1, -1LL * x * r);
}

long long get(int r){ return r * fwtA.get(r) - fwtB.get(r); }
long long get(int l, int r){ return get(r) - get(l - 1); }

const int MAXN = 2e5;
int n, q;
vector<int> adj[MAXN + 5];

int h[MAXN + 5], sz[MAXN + 5], par[MAXN + 5];
int Head[MAXN + 5], Pos[MAXN + 5], Time = 0;

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

void HLD(int u, int prv, int cHead){
    Head[u] = cHead;
    Pos[u] = ++Time;

    int nxt = -1;
    for(int v: adj[u]){
        if(v == prv) continue;
        if(nxt == -1 || sz[v] > sz[nxt]) nxt = v;
    }
    if(nxt != -1) HLD(nxt, u, cHead);

    for(int v: adj[u]){
        if(v == prv || v == nxt) continue;
        HLD(v, u, v);
    }
}

void query(int u, int v, int x){
    while(Head[u] != Head[v]){
        if(h[Head[u]] > h[Head[v]]) swap(u, v);

        range_update(Pos[Head[v]], Pos[v], x);
        v = par[Head[v]];
    }

    if(h[u] > h[v]) swap(u, v);
    range_update(Pos[u], Pos[v], x);
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

    fwtA = FenwickTree(n + 1);
    fwtB = FenwickTree(n + 1);

    dfs(1, 0);
    HLD(1, 0, 1);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int u;
            cin >> u;

            cout << get(Pos[u], Pos[u] + sz[u] - 1) << '\n';
        }
        else if(type == 2){
            int u;
            cin >> u;

            cout << get(Pos[u], Pos[u]) << '\n';
        }
        else{
            int u, v, x;
            cin >> u >> v >> x;

            query(u, v, x);
        }
    }

	return 0;
}
