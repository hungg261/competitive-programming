/******************************************************************************
Link: https://codeforces.com/problemset/problem/1416/D
Code: 1416D
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-20-19.42.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int MAXM = 3e5;
const int MAXQ = 5e5;

struct Edge{
    int u, v;
};

struct Query{
    int type, x, root;
};

struct DSU{
    int par[2 * MAXN + 5];

    void init(int sz){
        for(int i = 1; i <= sz; ++i) par[i] = i;
    }

    int find(int u){
        return par[u] == u ? u : par[u] = find(par[u]);
    }
};

int n, m, q, curNodes, timer;
int p[MAXN + 5], ord[MAXN + 5];
int tin[2 * MAXN + 5], tout[2 * MAXN + 5];
bool deleted[MAXM + 5];
Edge edges[MAXM + 5];
Query queries[MAXQ + 5];
vector<int> adj[2 * MAXN + 5];
DSU dsu;

struct SegTree{
    pair<int, int> st[4 * MAXN + 5];

    void build(int id, int l, int r){
        if(l == r){
            st[id] = {p[ord[l]], l};
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }

    void update(int id, int l, int r, int pos, int val){
        if(l == r){
            st[id] = {val, l};
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(id << 1, l, mid, pos, val);
        else update(id << 1 | 1, mid + 1, r, pos, val);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }

    pair<int, int> query(int id, int l, int r, int u, int v){
        if(v < l || r < u) return {-1, -1};
        if(u <= l && r <= v) return st[id];
        int mid = (l + r) >> 1;
        return max(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
    }
} seg;

namespace Solve{

void unite(int u, int v){
    u = dsu.find(u);
    v = dsu.find(v);
    if(u == v) return;
    ++curNodes;
    dsu.par[u] = dsu.par[v] = curNodes;
    adj[curNodes].push_back(u);
    adj[curNodes].push_back(v);
}

void dfs(int u){
    if(u <= n){
        tin[u] = tout[u] = ++timer;
        ord[timer] = u;
        return;
    }
    tin[u] = timer + 1;
    for(int v: adj[u]){
        dfs(v);
    }
    tout[u] = timer;
}

void solve(){
    curNodes = n;
    dsu.init(2 * n);

    for(int i = 1; i <= m; ++i){
        if(!deleted[i]){
            unite(edges[i].u, edges[i].v);
        }
    }

    for(int i = q; i >= 1; --i){
        if(queries[i].type == 1){
            queries[i].root = dsu.find(queries[i].x);
        }
        else{
            int idx = queries[i].x;
            unite(edges[idx].u, edges[idx].v);
        }
    }

    for(int u = curNodes; u >= 1; --u){
        if(dsu.find(u) == u){
            dfs(u);
        }
    }

    seg.build(1, 1, n);

    for(int i = 1; i <= q; ++i){
        if(queries[i].type == 1){
            int r = queries[i].root;
            pair<int, int> res = seg.query(1, 1, n, tin[r], tout[r]);
            cout << res.first << "\n";
            if(res.first > 0){
                seg.update(1, 1, n, res.second, 0);
            }
        }
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }
    for(int i = 1; i <= m; ++i){
        cin >> edges[i].u >> edges[i].v;
    }
    for(int i = 1; i <= q; ++i){
        cin >> queries[i].type >> queries[i].x;
        if(queries[i].type == 2){
            deleted[queries[i].x] = true;
        }
    }

    Solve::solve();

    return 0;
}
