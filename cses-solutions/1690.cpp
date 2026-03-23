#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    int adj[n][n];
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) adj[i][j] = 0;

    while(m--){
        int a, b; cin >> a >> b;
        --a; --b;
        ++adj[a][b];
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    dp[1][0] = 1;

    for(int mask = 1; mask < (1 << n); ++mask){
        if(!(mask & 1)) continue;
        if((mask & (1 << (n - 1))) && (mask != (1 << n) - 1)) continue;

        for(int i = 0; i < n; ++i){
            if(mask & (1 << i)){
                int prevMask = mask & (~(1 << i));
                for(int j = 0; j < n; ++j){
                    if(adj[j][i] > 0) dp[mask][i] = (dp[mask][i] + dp[prevMask][j] * adj[j][i]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = (ans + dp[(1 << n) - 1][i]) % MOD;
    }

    cout << ans << '\n';

    return 0;
}
