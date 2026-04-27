/******************************************************************************
Link: https://codeforces.com/contest/837/problem/D
Code: 837D
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-27-11.45.50
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 200, MAXVAL = 200 * 26;
int n, k;
int a[MAXN + 5], b[MAXN + 5];
int dp[2][MAXN + 5][MAXVAL + 5];

void solve(){
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; ++i){
        memset(dp[i & 1], -1, sizeof dp[i & 1]);
        for(int j = 0; j <= k; ++j){
            for(int s = 0; s <= MAXVAL; ++s){
                dp[i & 1][j][s] = max(dp[i & 1][j][s], dp[i - 1 & 1][j][s]);
                if(s >= a[i] && j >= 1 && dp[i - 1 & 1][j - 1][s - a[i]] != -1)
                    dp[i & 1][j][s] = max(dp[i & 1][j][s], dp[i - 1 & 1][j - 1][s - a[i]] + b[i]);
            }
        }
    }

    int res = 0;
    for(int s = MAXVAL; s >= 0; --s){
        res = max(res, min(s, dp[n & 1][k][s]));
    }
    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;

        while(cur % 5 == 0) cur /= 5, a[i]++;
        while(cur % 2 == 0) cur /= 2, b[i]++;
    }

    solve();

    return 0;
}
