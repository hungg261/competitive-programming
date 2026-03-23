/******************************************************************************
Link: https://cses.fi/problemset/task/2138
Code: 2138
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-17-15.18.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e4;
int n, m;
vector<int> adj[MAXN + 5];

bool vis[MAXN + 5];
int visited = 0;

int res[MAXN + 5];
void dfs(int u){
    if(vis[u]) return;
    vis[u] = true;


    for(int v: adj[u]){
        dfs(v);
    }

    ++visited;
    res[u] = visited;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    for(int u = 1; u <= n; ++u){
        dfs(u);
    }

    for(int u = 1; u <= n; ++u){
        cout << res[u] << ' ';
    }

    return 0;
}
