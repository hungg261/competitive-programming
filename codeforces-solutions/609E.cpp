/******************************************************************************
Link: https://codeforces.com/contest/609/problem/E
Code: 609E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-07-13.23.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct DSU{
    int n;
    vector<int> sz, par;

    DSU() = default;
    DSU(int _sz): n(_sz){
        sz.resize(_sz + 1);
        par.resize(_sz + 1);
    }

    void init(){
        for(int u = 1; u <= n; ++u)
            create(u);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
    }

    int find_set(int v){
        return par[v] == v ? v : find_set(par[v]);
    }

    bool union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];
            return true;
        }

        return false;
    }
};

struct Edge{
    int u, v, w, idx;
    bool removed = false;

    bool operator < (const Edge& other){
        return w < other.w;
    }
};

struct MaxPair{
    int first = -1, second = -1;

    void push(int v){
        if(v >= first){
            second = first;
            first = v;
        }
        else if(v >= second){
            second = v;
        }
    }
};

struct EdgeTo{
    int v, w;
};

const int MAXN = 2e5;
int n, m;
vector<EdgeTo> adj[MAXN + 5];
vector<Edge> edges;

int kruskal(){
    sort(begin(edges), end(edges));
    DSU dsu(n);
    dsu.init();

    int mst = 0;
    for(Edge& e: edges){
        if(dsu.union_set(e.u, e.v)){
            adj[e.u].push_back({e.v, e.w});
            adj[e.v].push_back({e.u, e.w});
            mst += e.w;
        }
        else e.removed = true;
    }

    return mst;
}

const int MAXLG = __lg(MAXN) + 1;
int h[MAXN + 5];
int table[MAXN + 5][MAXLG + 5];
int maxTable[MAXN + 5][MAXLG + 5];
void dfs(int u, int prv){
    for(const EdgeTo& e: adj[u]){
        if(e.v == prv) continue;

        h[e.v] = h[u] + 1;
        table[e.v][0] = u;
        maxTable[e.v][0] = e.w;

        dfs(e.v, u);
    }
}

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i <= n; ++i){
            table[i][j] = table[table[i][j - 1]][j - 1];
            maxTable[i][j] = max(maxTable[i][j - 1],
                                 maxTable[table[i][j - 1]][j - 1]);
        }
    }
}

pair<int, int> jump(int u, int steps){
    int maxVal = -1;
    for(int bit = MAXLG; bit >= 0; --bit){
        if(steps >> bit & 1){
            maxVal = max(maxVal, maxTable[u][bit]);
            u = table[u][bit];
        }
    }

    return {u, maxVal};
}

int find_lca_cost(int u, int v){
    if(h[u] > h[v]) swap(u, v);

    int maxVal = -1;
    tie(v, maxVal) = jump(v, h[v] - h[u]);

    if(u == v) return maxVal;

    for(int bit = MAXLG; bit >= 0; --bit){
        if(table[u][bit] != table[v][bit]){
            maxVal = max({maxVal,
                         maxTable[u][bit],
                         maxTable[v][bit]});

            u = table[u][bit];
            v = table[v][bit];
        }
    }


    maxVal = max({maxVal,
                 maxTable[u][0],
                 maxTable[v][0]});
    return maxVal;
}

void solve(){
    int mst = kruskal();
    vector<int> res(m + 1);

    dfs(1, 0);
    compute();
    for(const Edge& e: edges){
        if(!e.removed){
            res[e.idx] = mst;
        }
        else{
            res[e.idx] = mst + e.w - find_lca_cost(e.u, e.v);
        }
    }

    for(int i = 1; i <= m; ++i){
        cout << res[i] << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
         cin >> a >> b >> c;

         edges.push_back({a, b, c, i});
    }

    solve();

    return 0;
}
