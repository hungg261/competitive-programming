/******************************************************************************
Link: https://codeforces.com/contest/1187/problem/E
Code: 1187E
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-27-21.28.49
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int n;
vector<int> adj[MAXN + 5];

int sz[MAXN + 5];
void dfs(int u, int prv){
    sz[u] = 1;
    for(int v: adj[u]){
        if(v == prv) continue;

        dfs(v, u);
        sz[u] += sz[v];
    }
}

int sumSz[MAXN + 5];
void dfs1(int u, int prv){
    sumSz[u] = sz[u];
    for(int v: adj[u]){
        if(v == prv) continue;

        dfs1(v, u);
        sumSz[u] += sumSz[v];
    }
}

int res[MAXN + 5];
void dfs2(int u, int prv, int out){
    for(int v: adj[u]){
        if(v == prv) continue;

        int curOut = sumSz[u] - sumSz[v] - sz[v];
        int outSz = n - sz[v];

        int newOut = curOut + out + outSz;
        res[v] = curOut + out + sumSz[v] - sz[v] + n;

        dfs2(v, u, newOut);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    dfs1(1, -1);
    dfs2(1, -1, 0);

    int ans = sumSz[1];
    for(int u = 1; u <= n; ++u){
        ans = max(ans, res[u]);
    }

    cout << ans << "\n";

    return 0;
}
