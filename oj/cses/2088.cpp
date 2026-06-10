/******************************************************************************
Link: https://cses.fi/problemset/task/2088
Code: 2088
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-23-12.36.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5000;
int n, arr[MAXN + 5], pre[MAXN + 5];
array<int, 2> dp[MAXN + 5][MAXN + 5];

int cost(int l, int r){ return pre[r] - pre[l - 1]; }

void solve(){
    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= n; ++i){
        dp[i][i] = {0, i};
    }

    for(int len = 2; len <= n; ++len){
        for(int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;

            int L = dp[i][j - 1][1], R = dp[i + 1][j][1];
            for(int k = L; k <= R; ++k){
                if(k + 1 > j) break;

                dp[i][j] = min(dp[i][j],
                               {dp[i][k][0] + dp[k + 1][j][0] + cost(i, j), k});
            }
        }
    }

    cout << dp[1][n][0] << "\n";
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }

    solve();

    return 0;
}
