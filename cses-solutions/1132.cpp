/******************************************************************************
Link: https://cses.fi/problemset/task/1132
Code: 1132
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-22-21.56.26
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n;
vector<int> adj[MAXN + 5];

int dp[2][MAXN + 5];
pair<int, int> d[MAXN + 5];

void push(pair<int, int>& p, int u){
    if(dp[0][u] > dp[0][p.first]){
        p.second = p.first;
        p.first = u;
    }
    else if(dp[0][u] > dp[0][p.second]){
        p.second = u;
    }
}

void dfs(int u, int prv){
    for(int v: adj[u]){
        if(v == prv) continue;

        dfs(v, u);
        dp[0][u] = max(dp[0][u], dp[0][v] + 1);
    }

    for(int v: adj[u]){
        if(v == prv) continue;
        push(d[u], v);
    }
}

void Try(int u, int prv){
    for(int v: adj[u]){
        if(v == prv) continue;

        if(v == d[u].first)
            dp[1][v] = max(dp[1][u] + 1, dp[0][d[u].second] + 2);
        else
            dp[1][v] = max(dp[1][u] + 1, dp[0][d[u].first] + 2);

        Try(v, u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1132.INP","r",stdin);
    //freopen("1132.OUT","w",stdout);
    cin >> n;

    dp[0][0] = -1;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    Try(1, 0);

    for(int i = 1; i <= n; ++i){
        cout << max(dp[0][i], dp[1][i]) << ' ';
    }

    return 0;
}
