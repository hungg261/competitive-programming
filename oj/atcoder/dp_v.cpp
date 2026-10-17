/******************************************************************************
Link: https://atcoder.jp/contests/dp/tasks/dp_v
Code: dp_v
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-16-11.14.31
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
int n, MOD;
vector<int> adj[MAXN + 5];


namespace Solve{

int dp[MAXN + 5];
void dfs1(int u = 1, int prv = -1){
    dp[u] = 1;
    for(int v: adj[u]){
        if(v == prv) continue;
        dfs1(v, u);
        dp[u] = dp[u] * (dp[v] + 1) % MOD;
    }
}

int ans[MAXN + 5];
void dfs2(int curDP = 0, int u = 1, int prv = -1){
    ans[u] = dp[u] * (curDP + 1) % MOD;

    int k = (int)adj[u].size();
    vector<int> pre(k + 1), suf(k + 2);
    pre[0] = 1; suf[k + 1] = 1;

    for(int i = 1; i <= k; ++i){
        int v = adj[u][i - 1];
        if(v == prv) pre[i] = pre[i - 1];
        else pre[i] = pre[i - 1] * (dp[v] + 1) % MOD;
    }
    for(int i = k; i >= 1; --i){
        int v = adj[u][i - 1];
        if(v == prv) suf[i] = suf[i + 1];
        else suf[i] = suf[i + 1] * (dp[v] + 1) % MOD;
    }

    for(int i = 1; i <= k; ++i){
        int v = adj[u][i - 1];
        if(v == prv) continue;


        int new_curDP = pre[i - 1] * suf[i + 1] % MOD * (curDP + 1) % MOD;
        dfs2(new_curDP, v, u);
    }
}

void solve(){
    dfs1();
    dfs2();

    for(int u = 1; u <= n; ++u)
        cout << ans[u] << "\n";
}

}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> MOD;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Solve::solve();

    return 0;
}
