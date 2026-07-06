/******************************************************************************
Link: https://vjudge.net/problem/QOJ-6340
Code: QOJ-6340
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-06-11.00.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 1e5, MAXQ = 1e5, MAXLG = __lg(MAXN * 2) + 1;
int n, m, q;
int C[MAXM + 5];
vector<int> adj[MAXN + 5];
int h[MAXN + 5];

namespace E1{ int tin[MAXN + 5], tout[MAXN + 5], euler[MAXN + 5], Timer = 0; }
namespace E2{ int tin[MAXN * 2 + 5], Timer = 0; pair<int, int> table[MAXN * 2 + 5][MAXLG + 5]; }

void dfs(int u = 1, int prv = -1){
    E1::euler[E1::tin[u] = ++E1::Timer] = u;
    E2::table[E2::tin[u] = ++E2::Timer][0] = {h[u], u};
    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        dfs(v, u);
        E2::table[++E2::Timer][0] = {h[u], u};
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

namespace Set{

const int LG = __lg(MAXN) + 1;
int BIT[MAXN + 5];

void update(int idx, int val){
    for(int i = idx; i <= n; i += i & -i){
        BIT[i] += val;
    }
}

int get(int idx){
    int res = 0;
    for(int i = idx; i > 0; i -= i & -i){
        res += BIT[i];
    }
    return res;
}

inline int get(int l, int r){ return get(r) - get(l - 1); }

int find_right(int val){
    val = get(val - 1) + 1;

    int pos = 0;
    for(int i = 1 << MAXLG; i > 0; i >>= 1){
        if(pos + i <= n && BIT[pos + i] < val){
            pos += i;
            val -= BIT[pos];
        }
    }
    return pos + 1;
}

int find_left(int val){
    val = get(val);
    if(val == 0) return 0;

    int pos = 0;
    for(int i = 1 << MAXLG; i > 0; i >>= 1){
        if(pos + i <= n && BIT[pos + i] < val){
            pos += i;
            val -= BIT[pos];
        }
    }
    return pos + 1;
}

void debug(){
    for(int i = 1; i <= n; ++i){
        if(get(i, i)) cerr << E1::euler[i] << " " << get(i, i) << endl;
    }
    cerr << endl;
}

}

int qL = 1, qR = 0;
int res = 0;
void add(int u){
    int pos = E1::tin[u];

    int L = Set::find_left(pos);
    int R = Set::find_right(pos);

    Set::update(pos, 1);
    if(L != 0){ res += find_dist(u, E1::euler[L]); }
    if(R != n + 1){ res += find_dist(u, E1::euler[R]); }

    if(L != 0 && R != n + 1) res -= find_dist(E1::euler[L], E1::euler[R]);
}

void pop(int u){
    int pos = E1::tin[u];

    Set::update(pos, -1);
    int L = Set::find_left(pos);
    int R = Set::find_right(pos);

    if(L != 0){ res -= find_dist(u, E1::euler[L]); }
    if(R != n + 1){ res -= find_dist(u, E1::euler[R]); }

    if(L != 0 && R != n + 1) res += find_dist(E1::euler[L], E1::euler[R]);
}

int query(int l, int r){
    while(qL > l) add(C[--qL]);
    while(qR < r) add(C[++qR]);
    while(qL < l) pop(C[qL++]);
    while(qR > r) pop(C[qR--]);

    int out = res;
    int fi = Set::find_right(1), la = Set::find_left(n);
    if(fi != n + 1 && la != 0) out += find_dist(E1::euler[fi], E1::euler[la]);

    return out / 2 + 1;
}

const int BLOCKSIZE = 400;
void solve(){
    vector<array<int, 3>> queries;
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;

        queries.push_back({l, r, i});
    }

    sort(begin(queries), end(queries), [&](auto& x, auto& y){
            int b1 = x[0] / BLOCKSIZE, b2 = y[0] / BLOCKSIZE;
            if(b1 != b2) return b1 < b2;

            return (b1 & 1) ? x[1] < y[1] : x[1] > y[1];
         });

    vector<int> ans(q, -1);
    for(const array<int, 3> &qr: queries){
        ans[qr[2]] = query(qr[0], qr[1]);
    }

    for(int i = 0; i < q; ++i) cout << ans[i] << "\n";
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
