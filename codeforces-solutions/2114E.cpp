/******************************************************************************
Link: https://codeforces.com/problemset/problem/2114/E
Code: 2114E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-06-21.50.23
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int arr[MAXN + 5], n;
vector<int> adj[MAXN + 5];

int dp[MAXN + 5][2];

void dfs(int u, int prv){
    dp[u][0] = max(arr[u], arr[u] - dp[prv][1]);
    dp[u][1] = min(arr[u], arr[u] - dp[prv][0]);

    for(int v: adj[u]){
        if(v == prv) continue;

        dfs(v, u);
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; ++i) adj[i].clear();
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    for(int u = 1; u <= n; ++u){
        cout << max(dp[u][0], dp[u][1]) << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
