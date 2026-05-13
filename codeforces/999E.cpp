/******************************************************************************
Link: https://codeforces.com/contest/999/problem/E
Code: 999E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-13-14.18.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
const int INF = INT_MAX / 2;
int n, m, s, adj[MAXN + 5][MAXN + 5];
bool chosen[MAXN + 5][MAXN + 5];

vector<int> G[MAXN + 5];
int e[MAXN + 5], par[MAXN + 5];
int mark[MAXN + 5];

void dfs(int u){
    mark[u] = 1;

    for(int v: G[u]){
        if(mark[v] == 1){
            e[u] = INF;
            e[v] = INF;
            continue;
        }
        else if(mark[v] == 0){
            if(e[u] == INF) e[v] = INF;
            else if(e[u] + 1 > e[v]){
                e[v] = e[u] + 1;
                par[v] = u;
            }
            dfs(v);
        }

        if(e[u] == INF || e[v] == INF){
            e[u] = INF;
            e[v] = INF;
        }
        else if(e[u] + 1 > e[v]){
            e[v] = e[u] + 1;
            par[v] = u;
        }
    }

    mark[u] = 2;
}

void dijkstra(){
    vector<int> d(n + 1, INF);
    vector<bool> vis(n + 1, false);

    d[s] = 0;
    for(int i = 1; i <= n; ++i){
        int u = -1;
        for(int j = 1; j <= n; ++j){
            if(!vis[j] && (u == -1 || d[j] < d[u])){
                u = j;
            }
        }

        if(d[u] == INF) break;
        vis[u] = true;

        for(int v = 1; v <= n; ++v){
            if(vis[v]) continue;

            int newCost = d[u] + adj[u][v];
            if(newCost < d[v]){
                d[v] = newCost;
            }
        }
    }

    for(int u = 1; u <= n; ++u){
        for(int v = 1; v <= n; ++v){
            if(d[u] + adj[u][v] == d[v]){
                G[u].push_back(v);
            }
        }
    }

    memset(e, -1, sizeof e);
    memset(par, -1, sizeof par);
    e[s] = 0;
    dfs(s);

    int res = 0;
    for(int v = 1; v <= n; ++v){
        if(e[v] == INF || e[v] == -1) continue;

        int cur = v;
        while(par[cur] != -1){
            int prv = par[cur];

            if(adj[prv][cur] == 1 && !chosen[prv][cur]){
                chosen[prv][cur] = true;
                ++res;
            }
            cur = prv;
        }
    }

    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> s;
    for(int u = 1; u <= n; ++u)
        for(int v = 1; v <= n; ++v)
            adj[u][v] = 1;

    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a][b] = 0;
    }

    dijkstra();

    return 0;
}
