/******************************************************************************
Link: https://codeforces.com/contest/375/problem/D
Code: 375D
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-22-20.10.01
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 1e5;
int n, m;
int color[MAXN + 5];
vector<int> adj[MAXN + 5];
int tin[MAXN + 5], tout[MAXN + 5], euler[MAXN + 5], timerEuler = 0;
int cnt[MAXN + 5], geq[MAXN + 5], blockSize;
int ans[MAXM + 5];

struct Query{
    int l, r, k, id;
};

Query query[MAXM + 5];

void dfs(int u, int p){
    tin[u] = timerEuler;
    euler[timerEuler++] = u;
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    tout[u] = timerEuler - 1;
}

void add(int pos){
    int c = color[euler[pos]];
    ++cnt[c];
    ++geq[cnt[c]];
}

void pop(int pos){
    int c = color[euler[pos]];
    int f = cnt[c];
    --geq[f];
    --cnt[c];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) cin >> color[i];

    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    for(int i = 0; i < m; ++i){
        int v, k;
        cin >> v >> k;
        query[i] = {tin[v], tout[v], k, i};
    }

    blockSize = max(1, (int)sqrt(n));

    sort(query, query + m, [](const Query &a, const Query &b){
        int ba = a.l / blockSize, bb = b.l / blockSize;
        if(ba != bb) return ba < bb;
        return a.r < b.r;
    });

    int curL = 0, curR = -1;

    for(int i = 0; i < m; ++i){
        int l = query[i].l, r = query[i].r;

        while(curL > l) add(--curL);
        while(curR < r) add(++curR);
        while(curL < l) pop(curL++);
        while(curR > r) pop(curR--);

        ans[query[i].id] = geq[query[i].k];
    }

    for(int i = 0; i < m; ++i) cout << ans[i] << '\n';

    return 0;
}
