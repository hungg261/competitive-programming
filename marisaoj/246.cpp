/******************************************************************************
Link: https://marisaoj.com/problem/246
Code: 246
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-08-18.34.12
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
bool khop[MAXN + 5];
vector<int> adj[MAXN + 5];
int n, m;

int tin[MAXN + 5], low[MAXN + 5], Timer = 0;
void dfs_tree(int u, int prv){
    tin[u] = low[u] = ++Timer;

    int children = 0;
    for(int v: adj[u]){
        if(v == prv) continue;

        ++children;
        if(!tin[v]){
            dfs_tree(v, u);
            low[u] = min(low[u], low[v]);

            if(prv == -1){
                if(children > 1){
                    khop[u] = true;
                }
            }
            else if(tin[u] <= low[v]) khop[u] = true;
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

    for(int i = 1; i <= n; ++i)
        if(!tin[i]) dfs_tree(i, -1);

    cout << count(khop + 1, khop + n + 1, true) << '\n';
    for(int i = 1; i <= n; ++i){
        if(khop[i]) cout << i << ' ';
    }

    return 0;
}
