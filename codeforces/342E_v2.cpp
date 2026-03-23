/******************************************************************************
Link: https://codeforces.com/problemset/problem/342/E
Code: 342E
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-03-09.38.57
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXQ = 1e5, BLOCK = sqrt(MAXQ);
int n, q;
vector<int> adj[MAXN + 5];

namespace Sqrt{

int res[MAXN + 5];
vector<int> pending;
void bfs(){
    queue<pair<int, int>> que;
    for(int node: pending){
        que.push({node, 0});
        res[node] = 0;
    }

    while(!que.empty()){
        int u, cost;
        tie(u, cost) = que.front();
        que.pop();

        if(cost != res[u]) continue;

        for(int v: adj[u]){
            int newCost = res[u] + 1;
            if(newCost < res[v]){
                res[v] = newCost;
                que.push({v, newCost});
            }
        }
    }
}

}

namespace LCA{

const int MAXLG = __lg(MAXN * 2) + 1;
int h[MAXN + 5];
int tin[MAXN + 5], Timer = 0;
pair<int, int> table[MAXN * 2 + 5][MAXLG + 5];

void dfs(int u, int par){
    tin[u] = ++Timer;
    table[Timer][0] = {h[u], u};

    for(int v: adj[u]){
        if(v == par) continue;

        h[v] = h[u] + 1;
        dfs(v, u);

        table[++Timer][0] = {h[u], u};
    }
}

void computeLCA(){
    dfs(1, -1);
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= Timer; ++i){
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int find_lca(int u, int v){
    int l = tin[u], r = tin[v];
    if(l > r) swap(l, r);

    int bit = __lg(r - l + 1);
    return min(table[l][bit], table[r - (1 << bit) + 1][bit]).second;
}

int find_dist(int u, int v){
    return h[u] + h[v] - h[find_lca(u, v)] * 2;
}

}

using namespace Sqrt;
using namespace LCA;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(res, 0x3f, sizeof res);

    computeLCA();

    pending.push_back(1);
    for(int i = 1; i <= q; ++i){
        int type, x;
        cin >> type >> x;

        if(i % BLOCK == 0){
            bfs();
            pending.clear();
        }

        if(type == 1) pending.push_back(x);
        else{
            int ans = res[x];
            for(int node: pending){
                ans = min(ans, find_dist(x, node));
            }

            cout << ans << '\n';
        }
    }

    return 0;
}
