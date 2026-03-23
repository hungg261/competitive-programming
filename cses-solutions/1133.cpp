/******************************************************************************
Link: https://cses.fi/problemset/task/1133
Code: 1133
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-22-23.32.01
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
int n;
vector<int> adj[MAXN + 5];

int sz[MAXN + 5]; // so dinh nam trong cay con goc u
int outsz[MAXN + 5]; // so dinh nam ngoai cay con goc u

void dfs_Sz(int u, int prv){
    sz[u] = 1;
    for(int v: adj[u]){
        if(v == prv) continue;

        dfs_Sz(v, u);
        sz[u] += sz[v];
    }
}

void dfs_outSz(int u, int prv){
    outsz[u]++;
    for(int v: adj[u]){
        if(v == prv) continue;

        outsz[v] = outsz[u] + sz[u] - sz[v] - 1;
        dfs_outSz(v, u);
    }
}

int dp[2][MAXN + 5];

void dfs_down(int u, int prv){
    for(int v: adj[u]){
        if(v == prv) continue;

        dfs_down(v, u);

        dp[0][u] += dp[0][v] + sz[v];
    }
}

void dfs_up(int u, int prv){
    for(int v: adj[u]){
        if(v == prv) continue;

        dp[1][v] += dp[1][u] + outsz[u];
        dp[1][v] += dp[0][u] - dp[0][v] - sz[v] + (sz[u] - sz[v]);
        dp[1][v] -= 1;

        dfs_up(v, u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1133.INP","r",stdin);
    //freopen("1133.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_Sz(1, 0);
    dfs_outSz(1, 0);

    dfs_down(1, 0);
    dfs_up(1, 0);

    for(int u = 1; u <= n; ++u){
        cout << dp[0][u] + dp[1][u] << ' ';
    }

    return 0;
}
