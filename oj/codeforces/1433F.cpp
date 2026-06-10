/******************************************************************************
Link: https://codeforces.com/contest/1433/problem/F
Code: 1433F
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-22-15.58.27
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 70, MAXM = 70, MAXK = 70;
int n, m, k, a[MAXN + 5][MAXM + 5];

int dp[MAXM + 5][MAXK][MAXM / 2 + 5];
int best[MAXN + 5][MAXK];
void solve(){
    memset(best, -0x3f, sizeof best);
    best[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        memset(dp, -0x3f, sizeof dp);
        dp[0][0][0] = 0;
        for(int j = 1; j <= m; ++j){
            dp[j][0][0] = 0;
            for(int mod = 0; mod < k; ++mod){
                for(int c = 1; c <= m / 2; ++c){
                    int prv = (mod - a[i][j] % k + k) % k;
                    dp[j][mod][c] = max(dp[j - 1][mod][c], dp[j - 1][prv][c - 1] + a[i][j]);
                }
            }
        }

        for(int mod1 = 0; mod1 < k; ++mod1){
            int bestDp = *max_element(dp[m][mod1], dp[m][mod1] + m / 2 + 1);
            best[i][mod1] = max(best[i][mod1], best[i - 1][mod1]);
            for(int mod2 = 0; mod2 < k; ++mod2){
                int nxt = (mod1 + mod2) % k;
                best[i][nxt] = max(best[i][nxt], best[i - 1][mod2] + bestDp);
            }
        }
    }

    cout << best[n][0] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    solve();

    return 0;
}
