/******************************************************************************
Link: https://oj.vnoi.info/problem/mixup2
Code: mixup2
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-26-10.30.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) dp[(1 << n) - 1][i] = 1;
    for(int mask = (1 << n) - 1; mask >= 0; --mask){
        for(int i = 0; i < n; ++i){
            if(~mask >> i & 1) continue;
            for(int j = 0; j < n; ++j){
                if(i == j || (mask >> j & 1)) continue;

                if(abs(a[i] - a[j]) > k){
                    int next_mask = mask | (1 << j);
                    dp[mask][i] += dp[next_mask][j];
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n; ++i){
        res += dp[1 << i][i];
    }

    cout << res << "\n";

    return 0;
}
