/******************************************************************************
Link: https://oj.vnoi.info/problem/hsg_hcm_v2_25_hsnv
Code: hsg_hcm_v2_25_hsnv
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-16-14.54.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXM = 2e5, MAXQ = 2e5;
const int MAXLG = __lg(MAXN) + 1;
int N, M, Q, a[MAXM + 5];
vector<int> adj[MAXN + 5];
pair<int, int> table[MAXN * 2 + 5][MAXLG + 5];
int tin[MAXN + 5], Timer;
int h[MAXN + 5], lg[MAXN * 2 + 5];
long long hsnv[MAXM + 5];

void dfs(int u, int prv){
    tin[u] = ++Timer;
    table[Timer][0] = {h[u], u};
    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        dfs(v, u);
        table[++Timer][0] = {h[u], u};
    }
}

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) <= Timer; ++i){
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }

    lg[1] = 0;
    for(int i = 2; i <= N * 2; ++i){
        lg[i] = lg[i >> 1] + 1;
    }
}

int find_lca(int u, int v){
    int l = tin[u], r = tin[v];
    if(l > r) swap(l, r);

    int bit = lg[r - l + 1];
    return min(table[l][bit], table[r - (1 << bit) + 1][bit]).second;
}

int find_dist(int u, int v){
    return h[u] + h[v] - 2 * h[find_lca(u, v)];
}

namespace Subtask12{

void solve(){
    while(Q--){
        char type; cin >> type;

        if(type == 'e'){
            int X, V; cin >> X >> V;

            for(int nv = 1; nv <= M; ++nv){
                if(a[nv] == X){
                    hsnv[nv] += V;
                }
            }
        }
        else if(type == 't'){
            int L, R, Z;
            cin >> L >> R >> Z;

            for(int nv = L; nv <= R; ++nv){
                hsnv[nv] -= find_dist(a[nv], Z);
                a[nv] = Z;
            }
        }
        else if(type == 'q'){
            int K;
            cin >> K;

            cout << hsnv[K] << "\n";
        }
    }
}

};

namespace Subtask3{

long long delta[MAXN + 5];

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

    void add(int l, int r, long long val){
        update(l, val);
        if(r + 1 <= n) update(r + 1, -val);
    }

    long long get(int idx){
        if(idx <= 0) return 0;

        long long res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    long long get(int l, int r){ return get(r) - get(l - 1); }
};

struct Node{
    int l, r;
    int room;
    long long base;

    bool operator < (const Node& other) const {
        return l < other.l;
    }
};

set<Node> S;
FenwickTree fwt;

set<Node>::iterator split(int pos){
    auto it = S.lower_bound({pos, -1, -1, -1});
    if(it != S.end() && pos == it->l) return it;

    --it;
    if(it->r < pos) return S.end();

    int l = it->l, r = it->r,
        room = it->room;
    long long base = it->base;

    S.erase(it);
    S.insert({l, pos - 1, room, base});
    return S.insert({pos, r, room, base}).first;
}

void assign(int l, int r, int Z){
    auto itR = split(r + 1);
    auto itL = split(l);

    for(auto it = itL; it != itR; ++it){
        fwt.add(it->l, it->r, (delta[it->room] - it->base) - find_dist(it->room, Z));
    }

    S.erase(itL, itR);
    S.insert({l, r, Z, delta[Z]});
}

set<Node>::iterator find(int pos){
    auto it = prev(S.upper_bound({pos, -1, -1, -1}));
    return it;
}

long long query(int K){
    auto it = find(K);
    return fwt.get(K) + delta[it->room] - it->base;
}

void solve(){
    for(int i = 1; i <= M; ++i){
        S.insert({i, i, a[i], delta[a[i]]});
    }
    fwt = FenwickTree(M + 1);

    while(Q--){
        char type; cin >> type;

        if(type == 'e'){
            int X, V; cin >> X >> V;

            delta[X] += V;
        }
        else if(type == 't'){
            int L, R, Z;
            cin >> L >> R >> Z;

            assign(L, R, Z);
        }
        else if(type == 'q'){
            int K;
            cin >> K;

            cout << query(K) << "\n";
        }
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("HSNV.INP","r",stdin);
    freopen("HSNV.OUT","w",stdout);

    cin >> N >> M >> Q;
    for(int i = 1; i <= M; ++i){
        cin >> a[i];
    }
    for(int i = 1; i < N; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    compute();

    if(N <= 20000 && M <= 20000 && Q <= 20000) Subtask12::solve();
    else Subtask3::solve();

    return 0;
}
