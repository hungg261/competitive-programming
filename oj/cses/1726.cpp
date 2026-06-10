/******************************************************************************
Link: https://cses.fi/problemset/task/1726
Code: 1726
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-23-12.18.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXK = 100, MAXN = 8;
double dp[MAXK + 5][MAXN][MAXN],
        P[MAXN][MAXN];
int k;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void solve(){
    for(int x = 0; x < MAXN; ++x){
        for(int y = 0; y < MAXN; ++y){
            P[x][y] = 1;
        }
    }

    for(int i = 0; i < MAXN; ++i){
        for(int j = 0; j < MAXN; ++j){
            memset(dp, 0, sizeof dp);
            dp[0][i][j] = 1;

            for(int mv = 0; mv < k; ++mv){
                for(int x = 0; x < MAXN; ++x){
                    for(int y = 0; y < MAXN; ++y){

                        int deg = 0;
                        for(int d = 0; d < 4; ++d){
                            int nx = x + dx[d], ny = y + dy[d];
                            if(0 <= nx && nx < MAXN && 0 <= ny && ny < MAXN){
                                ++deg;
                            }
                        }

                        for(int d = 0; d < 4; ++d){
                            int nx = x + dx[d], ny = y + dy[d];
                            if(0 <= nx && nx < MAXN && 0 <= ny && ny < MAXN){
                                dp[mv + 1][nx][ny] += dp[mv][x][y] / deg;
                            }
                        }
                    }
                }
            }

            for(int x = 0; x < MAXN; ++x){
                for(int y = 0; y < MAXN; ++y){
                    P[x][y] *= 1 - dp[k][x][y];
                }
            }
        }
    }

    double res = 0;
    for(int x = 0; x < MAXN; ++x){
        for(int y = 0; y < MAXN; ++y){
            res += P[x][y];
        }
    }
    cout << fixed << setprecision(6) << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1726.INP","r",stdin);
    //freopen("1726.OUT","w",stdout);
    cin >> k;

    solve();

    return 0;
}
