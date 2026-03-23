/******************************************************************************
Link: https://codeforces.com/gym/100589/problem/G
Code: Gym_100589G
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-24-11.54.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<vector<long long>> dp(1 << n, vector<long long>(n, 0));
    for(int i = 0; i < n; ++i) dp[1 << i][i] = 1;

    for(int mask = 1; mask < (1 << n); ++mask){
        for(int i = 0; i < n; ++i){
            if(mask >> i & 1){
                int prevMask = mask ^ (1 << i);
                for(int j = 0; j < n; ++j){
                    if(i == j || abs(i - j) > k) continue;
                    if(mask >> j & 1){
                        dp[mask][i] += dp[prevMask][j];
                    }
                }
            }
        }
    }

    long long res = 0;
    for(int i = 0; i < n; ++i)
        res += dp[(1 << n) - 1][i];

    cout << res << '\n';
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
