/******************************************************************************
Link: https://codeforces.com/contest/1092/problem/F
Code: 1092F
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-03-09.38.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int n, a[MAXN + 5];
int h[MAXN + 5], subsum[MAXN + 5];
int total_sum = 0;
vector<int> adj[MAXN + 5];

int dp_down[MAXN + 5], dp_up[MAXN + 5];

void dfs_down(int u, int prv){
    subsum[u] = a[u];
    dp_down[u] = 0;
    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        dfs_down(v, u);

        subsum[u] += subsum[v];
        dp_down[u] += dp_down[v] + subsum[v];
    }
}

void dfs_up(int u, int prv){
    for(int v: adj[u]){
        if(v == prv) continue;

        dp_up[v] += dp_up[u] + (total_sum - subsum[v]);
        dp_up[v] += dp_down[u] - (dp_down[v] + subsum[v]);

        dfs_up(v, u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        total_sum += a[i];
    }

    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_down(1, -1);
    dfs_up(1, -1);

    int res = 0;
    for(int u = 1; u <= n; ++u){
        res = max(res, dp_down[u] + dp_up[u]);
    }

    cout << res << "\n";

    return 0;
}
