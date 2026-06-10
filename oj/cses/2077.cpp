/******************************************************************************
Link: https://cses.fi/problemset/task/2077
Code: 2077
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-21-19.24.26
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n, m;
vector<int> adj[MAXN + 5];

bool joint[MAXN + 5];
int tin[MAXN + 5], low[MAXN + 5], Timer = 0;
void dfs_tree(int u, int prv){
    tin[u] = low[u] = ++Timer;

    int children = 0;
    for(int v: adj[u]){
        if(v == prv) continue;

        if(!tin[v]){
            dfs_tree(v, u);
            low[u] = min(low[u], low[v]);

            if(prv == -1){
                if(++children > 1)
                    joint[u] = true;
            }
            else if(low[v] >= tin[u]) joint[u] = true;
        }
        else low[u] = min(low[u], tin[v]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int u = 1; u <= n; ++u)
        dfs_tree(u, -1);

    int cnt = 0;
    for(int u = 1; u <= n; ++u)
        cnt += joint[u];

    cout << cnt << "\n";
    for(int u = 1; u <= n; ++u)
        if(joint[u]) cout << u << " ";

    return 0;
}
