/******************************************************************************
Link: https://codeforces.com/contest/1628/problem/E
Code: 1628E
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-04-09.54.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
    }

    void init(){
        for(int u = 0; u <= n; ++u)
            create(u);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
    }

    int find(int v){
        return par[v] == v ? v : par[v] = find(par[v]);
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];

            return true;
        }

        return false;
    }
};

const int INF = 1e9 + 5;
const int MAXN = 3e5, MAXTWICE = MAXN * 2, MAXLG = __lg(MAXTWICE) + 1;
int n, q;
vector<int> adj[MAXTWICE + 5];
int h[MAXTWICE + 5];

struct Edge{
    int u, v, w;

    bool operator < (const Edge& other) const{
        return w < other.w;
    }
};
vector<Edge> edges;

namespace KRT{

int head;
int val[MAXTWICE + 5];

void build_KRT(){
    sort(begin(edges), end(edges));

    DSU dsu(n * 2);
    dsu.init();
    head = n;
    for(const Edge& e: edges){
        int fu = dsu.find(e.u),
            fv = dsu.find(e.v);

        if(fu == fv) continue;

        ++head;
        adj[head].push_back(fu);
        adj[head].push_back(fv);
        val[head] = e.w;

        dsu.par[fu] = dsu.par[fv] = head;
        dsu.sz[head] = dsu.sz[fu] + dsu.sz[fv];
    }

    h[head] = 0;
}

}
using namespace KRT;

namespace Seg2n{

const int MAXEULER = MAXTWICE * 2;
pair<int, int> table[MAXEULER * 2 + 5];
void update_mintable(int id, pair<int, int> newVal){
    --id;
    id += MAXEULER;

    table[id] = newVal;
    while(id > 1){
        id >>= 1;
        table[id] = min(table[id << 1], table[id << 1 | 1]);
    }
}

pair<int, int> get_mintable(int l, int r){
    --l;
    l += MAXEULER;
    r += MAXEULER;

    pair<int, int> res = {INF, -1};
    while(l < r){
        if(l & 1) res = min(res, table[l++]);
        if(r & 1) res = min(res, table[--r]);
        l >>= 1; r >>= 1;
    }
    return res;
}

}
using namespace Seg2n;

namespace Euler{

pair<int, int> tin[MAXTWICE + 5][MAXLG + 5];
int Timer = 0;
void dfs(int u, int par){
    update_mintable(++Timer, {h[u], u});
    tin[u][0] = {Timer, Timer};

    for(int v: adj[u]){
        if(v == par) continue;

        h[v] = h[u] + 1;

        dfs(v, u);
        update_mintable(++Timer, {h[u], u});
    }
}

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= head; ++i){
            tin[i][j].first = min(tin[i][j - 1].first, tin[i + (1 << (j - 1))][j - 1].first);
            tin[i][j].second = max(tin[i][j - 1].second, tin[i + (1 << (j - 1))][j - 1].second);
        }
    }
}

pair<int, int> get_minmax(int l, int r){
    int bit = __lg(r - l + 1);
    return {min(tin[l][bit].first, tin[r - (1 << bit) + 1][bit].first),
            max(tin[l][bit].second, tin[r - (1 << bit) + 1][bit].second)};
}

int __lca(int l, int r){
    return get_mintable(l, r).second;
}

int find_lca(int u, int v){
    int l = tin[u][0].first, r = tin[v][0].first;
    if(l > r) swap(l, r);

    return __lca(l, r);
}

}
using namespace Euler;

namespace SegmentTree{

struct Node{
    int mn = INF, mx = -INF, lazy = -1;

    void On(int l, int r){
        tie(mn, mx) = get_minmax(l, r);
        lazy = 1;
    }

    void Off(){
         mn = INF;
         mx = -INF;
         lazy = 0;
    }

    Node operator + (const Node& other) const{
        Node res;
        res.mn = min(mn, other.mn);
        res.mx = max(mx, other.mx);
        res.lazy = -1;
        return res;
    }
};

Node nodes[MAXN * 4 + 5];

void down(int id, int l, int r){
    int &lz = nodes[id].lazy;
    int mid = (l + r) >> 1;
    if(lz == -1) return;
    else if(lz == 0){
        nodes[id << 1].Off();
        nodes[id << 1 | 1].Off();
    }
    else if(lz == 1){
        nodes[id << 1].On(l, mid);
        nodes[id << 1 | 1].On(mid + 1, r);
    }

    lz = -1;
}

void On(int id, int l, int r, int u, int v){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        nodes[id].On(l, r);
        return;
    }

    down(id, l, r);

    int mid = (l + r) >> 1;
    On(id << 1, l, mid, u, v);
    On(id << 1 | 1, mid + 1, r, u, v);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

void Off(int id, int l, int r, int u, int v){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        nodes[id].Off();
        return;
    }

    down(id, l, r);

    int mid = (l + r) >> 1;
    Off(id << 1, l, mid, u, v);
    Off(id << 1 | 1, mid + 1, r, u, v);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

Node get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return Node();
    if(u <= l && r <= v) return nodes[id];

    down(id, l, r);

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

}
using namespace SegmentTree;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({a, b, c});
    }

    build_KRT();
    dfs(head, -1);
    compute();

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r;
            cin >> l >> r;

            On(1, 1, n, l, r);

        }
        else if(type == 2){
            int l, r;
            cin >> l >> r;

            Off(1, 1, n, l, r);
        }
        else{
            int x;
            cin >> x;

            bool was_on = get(1, 1, n, x, x).mn != INF;
            if(was_on) Off(1, 1, n, x, x);

            Node p = nodes[1];
            if(p.mn == INF){
                cout << "-1\n";
            }
            else{
                int lca = find_lca(__lca(p.mn, p.mx), x);
                cout << (val[lca]) << '\n';
            }

            if(was_on) On(1, 1, n, x, x);
        }
    }

    return 0;
}
