/******************************************************************************
Link: https://codeforces.com/problemset/problem/620/E
Code: 620E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-19-21.53.15
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;

long long nodes[MAXN * 4 + 5], lazy[MAXN * 4 + 5];

void apply(int id, long long lz){
    nodes[id] = lz;
    lazy[id] = lz;
}

void push(int id){
    long long &lz = lazy[id];
    if(lz == -1) return;

    apply(id << 1, lz);
    apply(id << 1 | 1, lz);

    lz = -1;
}

void assign(int id, int l, int r, int u, int v, long long mask){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        apply(id, mask);
        return;
    }

    push(id);

    int mid = (l + r) >> 1;
    assign(id << 1, l, mid, u, v, mask);
    assign(id << 1 | 1, mid + 1, r, u, v, mask);
    nodes[id] = nodes[id << 1] | nodes[id << 1 | 1];
}

long long get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return nodes[id];

    push(id);

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) | get(id << 1 | 1, mid + 1, r, u, v);
}

int n, q, a[MAXN + 5];
vector<int> adj[MAXN + 5];
int tin[MAXN + 5], tout[MAXN + 5], Timer = 0;

void dfs(int u, int prv){
    tin[u] = ++Timer;
    for(int v: adj[u]){
        if(v == prv) continue;
        dfs(v, u);
    }
    tout[u] = Timer;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    memset(lazy, -1, sizeof lazy);
    for(int i = 1; i <= n; ++i){
        assign(1, 1, Timer, tin[i], tin[i], 1LL << a[i]);
    }

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int v, c;
            cin >> v >> c;

            assign(1, 1, Timer, tin[v], tout[v], 1LL << c);
        }
        else{
            int v; cin >> v;
            cout << __builtin_popcountll(get(1, 1, Timer, tin[v], tout[v])) << "\n";
        }
    }

    return 0;
}
