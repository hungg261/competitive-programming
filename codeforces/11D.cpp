/******************************************************************************
Link: https://codeforces.com/contest/11/problem/D
Code: 11D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-24-19.57.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 19;
int n, m;
vector<int> adj[MAXN + 5];

long long dp[MAXN][1 << MAXN];
int s = 0;

long long dfs(int u, int mask){
    long long &memo = dp[u][mask];
    if(memo != -1) return memo;

    memo = 0;
    int len = __builtin_popcount(mask);
    for(int v: adj[u]){
        if(v == s && len >= 3) ++memo;
        else if((~mask >> v & 1) && v > s) memo += dfs(v, mask | (1 << v));
    }

    return memo;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        --a; --b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long res = 0;
    memset(dp, -1, sizeof dp);
    for(int u = 0; u < n; ++u){
        s = u;
        res += dfs(u, 1 << u);
    }

    cout << res / 2 << "\n";

    return 0;
}
