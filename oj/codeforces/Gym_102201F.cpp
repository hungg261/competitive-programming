/******************************************************************************
Link: https://codeforces.com/gym/102201/problem/F
Code: Gym_102201F
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-25-14.23.44
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 250'000, MAXQ = MAXN;
int n, q, c[MAXN + 5];
vector<int> adj[MAXN + 5];

namespace PST{

struct Node{
    int value;
    Node *l, *r;

    Node(int _value = 0): value(_value), l(NULL), r(NULL){}
    Node(Node *_l, Node *_r): value(_l->value + _r->value), l(_l), r(_r){}
    Node(Node *node): value(node->value), l(node->l), r(node->r){}
};

Node* nodes[MAXQ + 5];

Node *build(int l, int r){
    if(l == r){
        return new Node(0);
    }

    int mid = (l + r) >> 1;
    return new Node(build(l, mid), build(mid + 1, r));
}

Node *update(Node *node, int l, int r, int idx, int val){
    if(l == r){
        return new Node(node->value + val);
    }

    int mid = (l + r) >> 1;
    if(idx <= mid) return new Node(update(node->l, l, mid, idx, val), node->r);
    else return new Node(node->l, update(node->r, mid + 1, r, idx, val));
}

int get(Node *node, int l, int r, int u, int v){
    if(!node || r < u || v < l) return 0;
    if(u <= l && r <= v) return node->value;

    int mid = (l + r) >> 1;
    return get(node->l, l, mid, u, v) + get(node->r, mid + 1, r, u, v);
}

}

namespace Utils{

namespace LCA{

const int MAXLG = __lg(MAXN) + 1;
int h[MAXN + 5], table[MAXN + 5][MAXLG + 5];

int lift(int v, int dist){
    for(int b = MAXLG; b >= 0; --b)
        if(dist >> b & 1) v = table[v][b];
    return v;
}

int find(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    v = lift(v, h[v] - h[u]);

    if(u == v) return u;

    for(int b = MAXLG; b >= 0; --b){
        if(table[u][b] != table[v][b]){
            u = table[u][b];
            v = table[v][b];
        }
    }

    return table[u][0];
}

}

void dfs(int u = 1, int prv = -1){
    for(int j = 1; j <= LCA::MAXLG; ++j){
        LCA::table[u][j] = LCA::table[LCA::table[u][j - 1]][j - 1];
    }

    for(int v: adj[u]){
        if(v == prv) continue;

        LCA::h[v] = LCA::h[u] + 1;
        LCA::table[v][0] = u;

        dfs(v, u);
    }
}

int dist(int u, int v){
    return LCA::h[u] + LCA::h[v] - LCA::h[LCA::find(u, v)] * 2;
}

}

namespace Solve{

void dfs(int u = 1, int prv = 0){
    PST::nodes[u] = PST::update(PST::nodes[prv], 1, n, c[u], 1);
    for(int v: adj[u]){
        if(v == prv) continue;
        dfs(v, u);
    }
}

int getVal(int u, int v, int lca, int par_lca, int l, int r){
    return PST::get(PST::nodes[u], 1, n, l, r) + PST::get(PST::nodes[v], 1, n, l, r)
        - PST::get(PST::nodes[lca], 1, n, l, r) - PST::get(PST::nodes[par_lca], 1, n, l, r);
}

int query(int u, int v){
    int l = 1, r = n;
    int lca = Utils::LCA::find(u, v),
        par_lca = Utils::LCA::table[lca][0];

    int dist = Utils::dist(u, v) + 1;

    while(l < r){
        int mid = (l + r) >> 1;
        int valueL = getVal(u, v, lca, par_lca, l, mid);

        if(valueL * 2 > dist){
            r = mid;
        }
        else l = mid + 1;
    }

    return getVal(u, v, lca, par_lca, l, l) * 2 > dist ? l : -1;
}

void solve(){
    PST::nodes[0] = PST::build(1, n);
    dfs();
    for(int i = 1; i <= q; ++i){
        int u, v;
        cin >> u >> v;

        cout << query(u, v) << "\n";
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> c[i];
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Utils::dfs();
    Solve::solve();

    return 0;
}
