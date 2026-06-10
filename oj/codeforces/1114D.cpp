/******************************************************************************
Link: https://codeforces.com/contest/1114/problem/D
Code: 1114D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-14-08.36.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000, MAXVAL = 5000;
int c[MAXN + 5], n;
int dp[MAXN + 5][MAXN + 5][2];

void solve(){
    for(int i = 1; i <= n; ++i){
        dp[i][i][0] = dp[i][i][1] = 0;
    }

    for(int len = 2; len <= n; ++len){
        for(int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;

            dp[i][j][0] = min({
                            dp[i + 1][j][1] + (c[i] != c[j]),
                            dp[i + 1][j][0] + (c[i] != c[i + 1]),
                            dp[i][j - 1][1] + (c[j] != c[j - 1]) + (c[i] != c[j])
                        });
            dp[i][j][1] = min({
                            dp[i][j - 1][0] + (c[i] != c[j]),
                            dp[i][j - 1][1] + (c[j] != c[j - 1]),
                            dp[i + 1][j][0] + (c[i] != c[i + 1]) + (c[i] != c[j])
                        });
        }
    }

    cout << min(dp[1][n][0], dp[1][n][1]) << "\n";
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
