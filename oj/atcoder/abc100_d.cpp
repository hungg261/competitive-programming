/******************************************************************************
Link: https://atcoder.jp/contests/abc100/tasks/abc100_d
Code: abc100_d
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-24-16.20.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1000;
int n, m, a[MAXN + 5], b[MAXN + 5], c[MAXN + 5];

int dp[MAXN + 5][MAXN + 5][8];

void solve(){
    memset(dp, -0x3f, sizeof dp);
    for(int mask = 0; mask < 8; ++mask){
        dp[0][0][mask] = 0;
    }

    for(int i = 1; i <= n; ++i){
        for(int mask = 0; mask < 8; ++mask) dp[i][0][mask] = 0;
        for(int k = 1; k <= m; ++k){
            for(int mask = 0; mask < 8; ++mask){
                int cur = 0;
                if(mask & 1) cur += a[i];
                else cur -= a[i];
                if(mask & 2) cur += b[i];
                else cur -= b[i];
                if(mask & 4) cur += c[i];
                else cur -= c[i];

                dp[i][k][mask] = max(dp[i - 1][k][mask], dp[i - 1][k - 1][mask] + cur);
            }
        }
    }

    int res = -1;
    for(int mask = 0; mask < 8; ++mask){
        res = max(res, dp[n][m][mask]);
    }

    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i] >> b[i] >> c[i];
    }

    solve();

    return 0;
}
