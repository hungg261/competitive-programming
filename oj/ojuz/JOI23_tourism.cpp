/******************************************************************************
Link: https://oj.uz/problem/view/JOI23_tourism
Code: JOI23_tourism
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-05-20.47.50
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 1e5, MAXQ = 1e5, MAXLG = __lg(MAXN * 2) + 1;
int n, m, q;
int C[MAXM + 5];
vector<int> adj[MAXN + 5];
int h[MAXN + 5], sz[MAXN + 5], par[MAXN + 5];

namespace E1{ int tin[MAXN + 5], tout[MAXN + 5], euler[MAXN + 5], Timer = 0; }
namespace E2{ int tin[MAXN * 2 + 5], Timer = 0; pair<int, int> table[MAXN * 2 + 5][MAXLG + 5]; }

void dfs(int u = 1, int prv = -1){
    E1::euler[E1::tin[u] = ++E1::Timer] = u;
    E2::table[E2::tin[u] = ++E2::Timer][0] = {h[u], u};
    sz[u] = 1;
    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        par[v] = u;
        dfs(v, u);
        E2::table[++E2::Timer][0] = {h[u], u};
        sz[u] += sz[v];
    }
    E1::tout[u] = E1::Timer;
}

void compute(){
    dfs();
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= E2::Timer; ++i){
            E2::table[i][j] = min(E2::table[i][j - 1], E2::table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int find_lca(int u, int v){
    if(u == -1 || v == -1) return max(u, v);

    int l = E2::tin[u], r = E2::tin[v];
    if(l > r) swap(l, r);

    int bit = __lg(r - l + 1);
    int out = min(E2::table[l][bit], E2::table[r - (1 << bit) + 1][bit]).second;
    assert(1 <= out && out <= n);
    return out;
}

bool contains(int u, int v){ return E1::tin[u] <= E1::tin[v] && E1::tout[v] <= E1::tout[u]; }
int find_dist(int u, int v){ return h[u] + h[v] - h[find_lca(u, v)] * 2; }

namespace Brute{

int query(int l, int r){
    vector<int> S(C + l, C + r + 1);

    sort(begin(S), end(S), [&](int x, int y){ return E1::tin[x] < E1::tin[y]; });

    int res = 0;
    int sz = S.size();
    for(int i = 0; i < sz; ++i){
        res += find_dist(S[i], S[(i + 1) % sz]);
    }

    return res / 2 + 1;
}

void solve(){
    while(q--){
        int l, r;
        cin >> l >> r;

        cout << query(l, r) << "\n";
    }
}

}

namespace Solve{

namespace Segtree_LCA{

int nodes[MAXM * 4 + 5];
void build(int id = 1, int l = 1, int r = m){
    if(l == r){
        nodes[id] = C[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = find_lca(nodes[id << 1], nodes[id << 1 | 1]);
}

int get(int u, int v, int id = 1, int l = 1, int r = m){
    if(v < l || r < u) return -1;
    if(u <= l && r <= v) return nodes[id];

    int mid = (l + r) >> 1;
    return find_lca(get(u, v, id << 1, l, mid), get(u, v, id << 1 | 1, mid + 1, r));
}

}

namespace Segtree_HLD{

int BIT[MAXM + 5];

void update_cnt(int val, int delta){
    ++val;
    for(int i = val; i <= m + 1; i += i & -i) BIT[i] += delta;
}

int query_cnt(int val){
    ++val;

    int sum = 0;
    for(int i = val; i > 0; i -= i & -i) sum += BIT[i];
    return sum;
}

int get_total_count(int min_v, int max_v){
    if(min_v > max_v) return 0;
    return query_cnt(max_v) - query_cnt(min_v - 1);
}

struct Node{
    int l, r;
    mutable int v;
    bool operator<(const Node& o) const{ return l < o.l; }
};
set<Node> odt;

auto split(int pos){
    auto it = odt.lower_bound({pos, 0, 0});
    if(it != odt.end() && it->l == pos) return it;
    --it;
    if(it->r < pos) return odt.end();
    int l = it->l, r = it->r, v = it->v;
    odt.erase(it);
    odt.insert({l, pos - 1, v});
    return odt.insert({pos, r, v}).first;
}

void assign_set(int L, int R, int val){
    auto itr = split(R + 1);
    auto itl = split(L);
    for(auto it = itl; it != itr; ++it){
        update_cnt(it->v, -(it->r - it->l + 1));
    }
    odt.erase(itl, itr);
    odt.insert({L, R, val});
    update_cnt(val, R - L + 1);
}


int head[MAXN + 5], Pos[MAXN + 5], curPos = 0;
void HLD(int u = 1, int h = 1, int prv = -1){
    head[u] = h;
    Pos[u] = ++curPos;

    int nxt = -1;
    for(int v: adj[u]){
        if(v == prv) continue;

        if(nxt == -1 || sz[v] > sz[nxt]) nxt = v;
    }

    if(nxt != -1) HLD(nxt, h, u);

    for(int v: adj[u]){
        if(v == prv || v == nxt) continue;
        HLD(v, v, u);
    }
}

void update(int u, int val){
    int v = 1;
    while(head[u] != head[v]){
        assign_set(Pos[head[u]], Pos[u], val);
        u = par[head[u]];
    }
    assign_set(Pos[v], Pos[u], val);
}

int get(int l, int r){
    return get_total_count(l, r);
}

void init(){
    HLD();
    odt.insert({1, n, 0});
    update_cnt(0, n);
}

}

vector<pair<int, int>> queries[MAXQ + 5];
int pre[MAXN + 5];

void build_pre(int u = 1, int prv = -1){
    pre[u] = pre[prv] + 1;
    for(int v: adj[u]){
        if(v == prv) continue;
        build_pre(v, u);
    }
}

void solve(){
    Segtree_LCA::build();
    Segtree_HLD::init();
    build_pre();

    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;

        queries[r].emplace_back(l, i);
    }

    vector<int> res(q);
    for(int r = 1; r <= m; ++r){
        Segtree_HLD::update(C[r], r);
        for(const pair<int, int>& qr: queries[r]){
            int l, idx; tie(l, idx) = qr;

            res[idx] = Segtree_HLD::get(l, r) - pre[Segtree_LCA::get(l, r)];
        }
    }

    for(int i = 0; i < q; ++i) cout << res[i] + 1 << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= m; ++i) cin >> C[i];
    compute();

    Solve::solve();

    return 0;
}
