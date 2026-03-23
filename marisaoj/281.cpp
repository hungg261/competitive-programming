/******************************************************************************
Link: https://marisaoj.com/problem/281
Code: 281
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-20-00.23.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXQ = 1e5, MAXK = __lg(MAXN) + 1;
int n, q, arr[MAXN + 5], m;
int h[MAXN + 5], table[MAXN + 5][MAXK + 5];
vector<int> adj[MAXN + 5];

int temp[MAXN + 5];
void compress(){
    for(int i = 1; i <= n; ++i) temp[i] = arr[i];
    sort(temp + 1, temp + n + 1);
    m = unique(temp + 1, temp + n + 1) - temp - 1;

    for(int i = 1; i <= n; ++i){
        arr[i] = lower_bound(temp + 1, temp + m + 1, arr[i]) - temp;
    }
}

int St[MAXN + 5], En[MAXN + 5], Euler[MAXN * 2 + 5], Time = 0;

void dfs(int u, int prv){
    Euler[++Time] = u;
    St[u] = Time;

    for(int v: adj[u]){
        if(v == prv) continue;

        table[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
    }

    Euler[++Time] = u;
    En[u] = Time;
}

void compute(){
    for(int j = 1; j <= MAXK; ++j){
        for(int i = 1; i <= n; ++i){
            table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
}

int lift(int u, int s){
    for(int bit = MAXK; bit >= 0; --bit){
        if(s >> bit & 1) u = table[u][bit];
    }
    return u;
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    v = lift(v, h[v] - h[u]);

    if(u == v) return u;

    for(int bit = MAXK; bit >= 0; --bit){
        if(table[u][bit] != table[v][bit]){
            u = table[u][bit];
            v = table[v][bit];
        }
    }
    return table[u][0];
}

const int BLOCKSIZE = 300;
struct Query{
    int l, r, lca, idx;

    bool operator < (const Query& other){
        int blockL = l / BLOCKSIZE;
        int blockR = other.l / BLOCKSIZE;

        if(blockL == blockR){
            return (blockL & 1) ? r < other.r : r > other.r;
        }

        return blockL < blockR;
    }
} queries[MAXQ + 5];

pair<int, int> nodes[MAXN * 2 + 5];
void update(int id, int val){
    int idx = id;
    id = id - 1 + m;

    nodes[id] = {val, idx};

    while(id > 1){
        id >>= 1;
        nodes[id] = max(nodes[id << 1], nodes[id << 1 | 1]);
    }
}

int freq[MAXN + 5];
int vis[MAXN + 5];

void check(int u){
    vis[u] ^= 1;
    if(vis[u]){
        ++freq[arr[u]];
    }
    else{
        --freq[arr[u]];
    }

    update(arr[u], freq[arr[u]]);
}

void solve(){
    sort(queries + 1, queries + q + 1);

    int pl = 1, pr = 0;
    vector<int> answers(q + 1);
    for(int i = 1; i <= q; ++i){
        int res = -1;

        int l = queries[i].l, r = queries[i].r, lca = queries[i].lca;
        int u = Euler[l], v = Euler[r];
        int len = h[u] + h[v] - 2 * h[lca];

        while(pl > l) check(Euler[--pl]);
        while(pr < r) check(Euler[++pr]);
        while(pl < l) check(Euler[pl++]);
        while(pr > r) check(Euler[pr--]);

        if(lca != u && lca != v) check(lca);

        if(nodes[1].first > (len + 1) / 2){
            res = temp[nodes[1].second];
        }

        answers[queries[i].idx] = res;

        if(lca != u && lca != v) check(lca);
    }

    for(int i = 1; i <= q; ++i){
        cout << answers[i] << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("281.INP","r",stdin);
    //freopen("281.OUT","w",stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    compress();
    dfs(1, 0);
    compute();

    for(int i = 1; i <= q; ++i){
        int u, v;

        cin >> u >> v;

        if(St[u] > St[v]) swap(u, v);

        int lca = find_lca(u, v);

        if(lca == u) queries[i] = {St[u], St[v], lca, i};
        else queries[i] = {En[u], St[v], lca, i};
    }

    solve();

    return 0;
}
