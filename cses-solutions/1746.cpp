/******************************************************************************
Link: https://cses.fi/problemset/task/1746
Code: 1746
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-12-00.06.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 100;
const int MOD = 1e9 + 7;
int n, m, a[MAXN + 5];

int dp[MAXN + 5][MAXM + 5];
void solve(){
    if(a[1] == 0) fill(dp[1] + 1, dp[1] + m + 1, 1);
    else dp[1][a[1]] = 1;

    for(int i = 2; i <= n; ++i){
        if(a[i] == 0){
            for(int j = 1; j <= m; ++j){
                for(int new_value = j - 1; new_value <= j + 1; ++new_value){
                    if(1 <= new_value && new_value <= m){
                        (dp[i][j] += dp[i - 1][new_value]) %= MOD;
                    }
                }
            }
        }
        else{
            for(int new_value = a[i] - 1; new_value <= a[i] + 1; ++new_value){
                if(1 <= new_value && new_value <= m){
                    (dp[i][a[i]] += dp[i - 1][new_value]) %= MOD;
                }
            }
        }
    }

    int ans = 0;
    if(a[n] == 0){
        for(int j = 1; j <= m; ++j){
            (ans += dp[n][j]) %= MOD;
        }
    }
    else ans = dp[n][a[n]];

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    solve();
    return 0;
}
