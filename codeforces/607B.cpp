/******************************************************************************
Link: https://codeforces.com/contest/607/problem/B
Code: 607B
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-26-10.02.13
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500;
int n, c[MAXN + 5];
int dp[MAXN + 5][MAXN + 5];

void solve(){
    for(int i = 1; i <= n; ++i){
        dp[i][i] = 1;
        dp[i][i + 1] = (c[i] == c[i + 1] ? 1 : 2);
    }

    for(int len = 3; len <= n; ++len){
        for(int l = 1; l + len - 1 <= n; ++l){
            int r = l + len - 1;

            dp[l][r] = dp[l + 1][r] + 1;
            for(int k = l + 1; k <= r; ++k){
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);

                if(k > l + 1 && c[l] == c[k])
                    dp[l][r] = min(dp[l][r], dp[l + 1][k - 1] + dp[k + 1][r]);
            }
        }
    }

    cout << dp[1][n] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }

    solve();

    return 0;
}
