/******************************************************************************
Link: https://cses.fi/problemset/task/1160
Code: 1160
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-26-08.01.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz;

    DSU() = default;
    DSU(int _n){
        resize(_n);
    }

    void resize(int _n){
        n = _n;
        par.resize(_n + 1);
        sz.resize(_n + 1);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
    }

    int find_set(int v){
        return par[v] == v ? v : par[v] = find_set(par[v]);
    }

    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];
        }
    }

    void init(){
        for(int v = 1; v <= n; ++v) create(v);
    }
};

const int MAXN = 2e5, MAXLG = __lg(MAXN) + 1;
int n, q, nxt[MAXN + 5][MAXLG + 5];

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i <= n; ++i){
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        }
    }
}

int lift(int pos, int steps){
    for(int bit = MAXLG; bit >= 0; --bit){
        if(steps >> bit & 1){
            pos = nxt[pos][bit];
        }
    }

    return pos;
}

DSU dsu;

int mark[MAXN + 5];
int cycle[MAXN + 5], cycID = 0;
int cycleLen[MAXN + 5];

int h[MAXN + 5];

void process(int u){
    if(mark[u] > 0){
        return;
    }
    else if(mark[u] == -1){
        return;
    }
    else if(mark[u] == -2){
        int cur = u;
        int idx = 0;

        mark[cur] = ++idx;
        cycle[cur] = ++cycID;
        ++cycleLen[cycID];

        while(nxt[cur][0] != u){
            cur = nxt[cur][0];

            mark[cur] = ++idx;
            cycle[cur] = cycID;
            ++cycleLen[cycID];
        }
        return;
    }

    mark[u] = -2;
    cycle[u] = -1;

    process(nxt[u][0]);
    if(cycle[u] == -1) h[u] = h[nxt[u][0]] + 1;

    if(mark[u] == -2) mark[u] = -1;
}

int query(int u, int v){
    if(dsu.find_set(u) != dsu.find_set(v)) return -1;

    if(mark[u] > 0 && mark[v] > 0){
        if(mark[u] <= mark[v]) return mark[v] - mark[u];
        else return cycleLen[cycle[u]] - (mark[u] - mark[v]);
    }
    else if(mark[u] > 0 && mark[v] < 0) return -1;
    else if(mark[u] < 0 && mark[v] > 0){
        int parroot = lift(u, h[u]);
        int in_cycle = mark[parroot] <= mark[v] ? mark[v] - mark[parroot] : cycleLen[cycle[v]] - (mark[parroot] - mark[v]);

        return h[u] + in_cycle;
    }
    else if(mark[u] < 0 && mark[v] < 0){
        if(h[u] < h[v]) return -1;

        int lifted = lift(u, h[u] - h[v]);
        if(lifted == v) return h[u] - h[v];
        else return -1;
    }
    return -1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1160.INP","r",stdin);
    //freopen("1160.OUT","w",stdout);
    cin >> n >> q;
    dsu = DSU(n);
    dsu.init();

    for(int i = 1; i <= n; ++i){
        cin >> nxt[i][0];
        dsu.union_sets(i, nxt[i][0]);
    }
    compute();

    for(int i = 1; i <= n; ++i) process(i);

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << query(a, b) << '\n';
    }

    return 0;
}
