#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10, MAXM = 1000;
int dp[MAXM + 5][MAXN + 5][(1 << MAXN) + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    const int MOD = 1e9 + 7;

    dp[0][n - 1][(1 << n) - 1] = 1;
    for(int col = 1; col <= m; ++col){
        for(int row = 0; row < n; ++row){
            for(int mask = 0; mask < (1 << n); ++mask){
                if(row == 0){
                    dp[col][0][mask] += dp[col - 1][n - 1][mask ^ 1];
                    dp[col][0][mask] %= MOD;
                    continue;
                }

                if(mask & (1 << row)){
                    dp[col][row][mask] += dp[col][row - 1][mask & (~(1 << row))];
                    dp[col][row][mask] %= MOD;

                    if(mask & (1 << (row - 1))){
                        dp[col][row][mask] += dp[col][row - 1][mask & (~(1 << (row - 1)))];
                        dp[col][row][mask] %= MOD;
                    }
                }
                else{
                    dp[col][row][mask] += dp[col][row - 1][mask | (1 << row)];
                    dp[col][row][mask] %= MOD;
                }
            }
        }
    }

    cout << dp[m][n - 1][(1 << n) - 1] << '\n';

    return 0;
}
