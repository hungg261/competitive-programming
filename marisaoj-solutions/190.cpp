/******************************************************************************
Link: https://marisaoj.com/problem/190
Code: 190
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-04-09.57.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e15;
const int MAXN = 1e5, MAXK = 100;
vector<int> L[MAXN + 5];
int dp[MAXN + 5][MAXK + 5];
int pre[MAXN + 5], n, k;

void solve_dp(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int r = 1; r <= n; ++r){
        dp[r][0] = 0;
        for(int j = k; j >= 1; --j){
            dp[r][j] = dp[r - 1][j];
            for(int l: L[r]){
                dp[r][j] = min(dp[r][j], dp[l - 1][j - 1] + (pre[r] - pre[l - 1]));
            }
        }
    }
}

vector<int> adj[MAXN + 5];
int w[MAXN + 5];
int St[MAXN + 5], Time = 0;

void dfs(int u, int prv){
    St[u] = ++Time;
    pre[Time] = pre[Time - 1] + w[u];

    for(int v: adj[u]){
        if(v == prv) continue;
        dfs(v, u);
    }

    L[Time].push_back(St[u]);
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> w[i];
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    solve_dp();

    int ans = pre[n] - *min_element(dp[n], dp[n] + k + 1);
    cout << ans << '\n';

	return 0;
}
