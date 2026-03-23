#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int INF = 1e9;
int n;
vector<int> adj[MAXN + 5];

int dp[2][MAXN + 5];
void dfs(int node, int parent){
    dp[0][node] = 0;
    dp[1][node] = -INF;

    for(int dest: adj[node]){
        if(dest != parent){
            dfs(dest, node);
            dp[0][node] += max(dp[0][dest], dp[1][dest]);
            dp[1][node] = max(dp[1][node], dp[0][dest] - max(dp[0][dest], dp[1][dest]));
        }
    }

    dp[1][node] += dp[0][node];
    ++dp[1][node];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n   - 1; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    int ans = max(dp[0][1], dp[1][1]);
    cout << ans << '\n';

    return 0;
}
