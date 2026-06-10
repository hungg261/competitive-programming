#include<bits/stdc++.h>
using namespace std;

#define int long long

void dfs(int u, int prev, const vector<vector<int>>& adj, vector<int>& deg, vector<int>& best){
    best[u] = deg[u];
    for(int v: adj[u]){
        if(v == prev) continue;

        dfs(v, u, adj, deg, best);
        best[u] = max(best[u], best[v]);
    }
}

void solve(int u, int prev, const vector<vector<int>>& adj, vector<int>& deg, vector<int>& best, int& ans){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int v: adj[u]){
        if(v == prev) continue;

        ans = max(ans, deg[u] + deg[v] - 2);
        ans = max(ans, deg[prev] + best[v] - 1);

        solve(v, u, adj, deg, best, ans);

        pq.push(best[v]);
        if(pq.size() > 2) pq.pop();
    }

    while(pq.size() < 2) pq.push(-1000000000);

    int L = pq.top(); pq.pop();
    int R = pq.top(); pq.pop();
    ans = max(ans, L + R - 1);
}

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);
    vector<int> best(n + 1, 0);

    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
        ++deg[a]; ++deg[b];
    }
    deg[0] = -1e9;

    dfs(1, 0, adj, deg, best);
//    for(int i = 1; i <= n; ++i) cout << deg[i] << ' ' << best[i] << '\n'; cout << '\n';

    int ans = -1;
    solve(1, 0, adj, deg, best, ans);

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
