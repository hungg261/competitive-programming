/******************************************************************************
Link: https://oj.uz/problem/view/JOI23_currencies
Code: JOI23_currencies
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-13-09.21.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5, MAXM = 1e5, MAXQ = 1e5, MAXLG = __lg(MAXN * 2) + 1;
int n, m, q;
struct EdgeTo{ int v; };
vector<EdgeTo> adj[MAXN + 5];

struct Checkpoint{
    int C, u;
    bool operator < (const Checkpoint& other){
        return C < other.C;
    }
} Checkpoints[MAXM + 5];
struct Query{ int s, t, x, y; } Queries[MAXQ + 5];

int h[MAXN + 5];
namespace E1{ int tin[MAXN + 5], tout[MAXN + 5], Timer = 0; }
namespace E2{ int tin[MAXN + 5], Timer = 0; pair<int, int> table[MAXN * 2 + 5][MAXLG + 5]; }
void dfs(int u = 1, int prv = -1){
    E1::tin[u] = ++E1::Timer;
    E2::table[E2::tin[u] = ++E2::Timer][0] = {h[u], u};
    for(const EdgeTo& e: adj[u]){
        if(e.v == prv) continue;
        h[e.v] = h[u] + 1;
        dfs(e.v, u);

        E2::table[++E2::Timer][0] = {h[u], u};
    }
    E1::tout[u] = ++E1::Timer;
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
    int l = E2::tin[u], r = E2::tin[v];
    if(l > r) swap(l, r);

    int bit = __lg(r - l + 1);
    return min(E2::table[l][bit], E2::table[r - (1 << bit) + 1][bit]).second;
}

namespace Solve{

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

FenwickTree fwt;

inline void add(int u, int w){
    fwt.update(E1::tin[u], w);
    fwt.update(E1::tout[u], -w);
}
inline int get(int u){ return fwt.get(E1::tin[u]); }
inline int get(int u, int v){ return get(u) + get(v) - get(find_lca(u, v)) * 2; }

int L[MAXQ + 5], R[MAXQ + 5];
vector<int> candidates[MAXM + 5];
void solve(){
    for(int i = 1; i <= q; ++i)
        L[i] = 0, R[i] = m;

    sort(Checkpoints + 1, Checkpoints + m + 1);

    while(true){
        bool changed = false;
        for(int i = 1; i <= q; ++i){
            if(L[i] >= R[i]) continue;

            int mid = (L[i] + R[i] + 1) >> 1;
            candidates[mid].push_back(i);
            changed = true;
        }
        if(!changed) break;

        fwt = FenwickTree(E1::Timer);
        for(int i = 1; i <= m; ++i){
            const Checkpoint& Cp = Checkpoints[i];
            add(Cp.u, Cp.C);

            for(int x: candidates[i]){
                const Query& Q = Queries[x];
                if(get(Q.s, Q.t) <= Q.y) L[x] = i;
                else R[x] = i - 1;
            }

            candidates[i].clear();
        }
    }

    fwt = FenwickTree(E1::Timer);

    vector<int> qs(q); iota(begin(qs), end(qs), 1);
    sort(begin(qs), end(qs), [&](int x, int y){ return L[x] < L[y]; });
    int pos = 1;
    for(int i = 0; i < q; ++i){
        while(pos <= L[qs[i]]) add(Checkpoints[pos++].u, 1);

        const Query& Q = Queries[qs[i]];
        L[qs[i]] = get(Q.s, Q.t);
    }
    while(pos <= m) add(Checkpoints[pos++].u, 1);

    for(int i = 1; i <= q; ++i){
        const Query& Q = Queries[i];
        int gold = get(Q.s, Q.t) - L[i];

        if(gold > Q.x) cout << "-1\n";
        else cout << Q.x - gold << "\n";
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;

    vector<pair<int, int>> edges;
    edges.emplace_back();
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back({b});
        adj[b].push_back({a});
        edges.emplace_back(a, b);
    }

    compute();

    for(int i = 1; i <= m; ++i){
        int P, C;
        cin >> P >> C;

        int u, v; tie(u, v) = edges[P];
        if(E1::tin[u] > E1::tin[v]) swap(u, v);

        Checkpoints[i] = {C, v};
    }

    for(int i = 1; i <= q; ++i){
        int s, t, x, y;
        cin >> s >> t >> x >> y;

        Queries[i] = {s, t, x, y};
    }

    Solve::solve();

    return 0;
}
