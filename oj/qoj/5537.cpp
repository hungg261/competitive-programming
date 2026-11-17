/******************************************************************************
Link: https://vjudge.net/problem/QOJ-5537
Code: 5537
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-15-22.43.21
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3, MAXM = 100, MAXK = MAXM * 3;
int n, m, k;
string grid[MAXN];

string fmask(int mask){
    return bitset<MAXN>(mask).to_string();
}

inline int pow2(int x){ return x * x; }
inline int dist(int x1, int y1, int x2, int y2){
    return pow2(x1 - x2) + pow2(y1 - y2);
}

int dp[MAXM][1 << MAXN][MAXK + 1];
void solve(){
    memset(dp, -1, sizeof dp);

    for(int j = 0; j < m; ++j){
        for(int mask = 0; mask < (1 << n); ++mask){
            if(![&](){
                for(int i = 0; i < n; ++i){
                    if((mask >> i & 1) && grid[i][j] == '#') return false;
                }
                return true;
            }()) continue;

            int cnt = __builtin_popcount(mask);

            int default_dist = INT_MAX;
            for(int i = 0; i < n; ++i){
                if(~mask >> i & 1) continue;
                for(int row_i = 0; row_i < n; ++row_i){
                    if(~mask >> row_i & 1) continue;
                    if(row_i != i)
                        default_dist = min(default_dist, dist(i, j, row_i, j));
                }
            }

            dp[j][mask][cnt] = max(dp[j][mask][cnt], default_dist);
            if(j == 0) continue;

            for(int prv_j = 0; prv_j < j; ++prv_j){
                for(int prv_mask = 0; prv_mask < (1 << n); ++prv_mask){
                    if(![&](){
                        for(int prv_i = 0; prv_i < n; ++prv_i){
                            if((prv_mask >> prv_i & 1) && grid[prv_i][prv_j] == '#') return false;
                        }
                        return true;
                    }()) continue;

                    int taken = cnt + __builtin_popcount(prv_mask);
                    for(int c = taken; c <= k; ++c){
                        int min_dist = default_dist;
                        for(int i = 0; i < n; ++i){
                            if(~mask >> i & 1) continue;

                            for(int prv_i = 0; prv_i < n; ++prv_i){
                                if(~prv_mask >> prv_i & 1) continue;
                                if(i == prv_i && j == prv_j) continue;

                                min_dist = min(min_dist, dist(i, j, prv_i, prv_j));
                            }
                        }

                        if(min_dist != INT_MAX){
                            dp[j][mask][c] = max(dp[j][mask][c], min(dp[prv_j][prv_mask][c - cnt], min_dist));
                        }
                    }
                }
            }
        }
    }

    int res = 0;
    for(int j = 0; j < m; ++j){
        for(int mask = 0; mask < (1 << n); ++mask){
            res = max(res, dp[j][mask][k]);
            cerr << j << " " << fmask(mask) << " " << k << ": " << dp[j][mask][k] << endl;
        }
    }

    if(res > 0) cout << fixed << setprecision(6) << sqrt(res) << "\n";
    else cout << "-1\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> k;
    n = 3;

    for(int i = 0; i < n; ++i){
        cin >> grid[i];
    }

    solve();

    return 0;
}

// FIXME: WA
