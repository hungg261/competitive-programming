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

int nxt[MAXN][MAXM + 5];
int dp[MAXM + 5][MAXM + 5][MAXM + 5];

bool check(int dist){
    int req[MAXN][MAXN] = {};
    for(int r1 = 0; r1 < n; ++r1){
        for(int r2 = 0; r2 < n; ++r2){
            int a = (r1 - r2) * (r1 - r2),
                b = dist - a;

            int d = sqrt(max(0, b));
            while(d * d < b) ++d;

            req[r1][r2] = d;
        }
    }

    memset(dp, -1, sizeof dp);
    int res = dp[0][0][0] = 0;

    for(int c0 = 0; c0 <= m; ++c0){
        for(int c1 = 0; c1 <= m; ++c1){
            for(int c2 = 0; c2 <= m; ++c2){
                if(dp[c0][c1][c2] == -1) continue;

                res = max(res, dp[c0][c1][c2]);
                if(res >= k) return true;

                int nxt0 = 1;
                if(c0) nxt0 = max(nxt0, c0 + req[0][0]);
                if(c1) nxt0 = max(nxt0, c1 + req[0][1]);
                if(c2) nxt0 = max(nxt0, c2 + req[0][2]);
                nxt0 = nxt[0][min(nxt0, m + 1)];
                if(nxt0 <= m) dp[nxt0][c1][c2] = max(dp[nxt0][c1][c2], dp[c0][c1][c2] + 1);

                int nxt1 = 1;
                if(c0) nxt1 = max(nxt1, c0 + req[1][0]);
                if(c1) nxt1 = max(nxt1, c1 + req[1][1]);
                if(c2) nxt1 = max(nxt1, c2 + req[1][2]);
                nxt1 = nxt[1][min(nxt1, m + 1)];
                if(nxt1 <= m) dp[c0][nxt1][c2] = max(dp[c0][nxt1][c2], dp[c0][c1][c2] + 1);

                int nxt2 = 1;
                if(c0) nxt2 = max(nxt2, c0 + req[2][0]);
                if(c1) nxt2 = max(nxt2, c1 + req[2][1]);
                if(c2) nxt2 = max(nxt2, c2 + req[2][2]);
                nxt2 = nxt[2][min(nxt2, m + 1)];
                if(nxt2 <= m) dp[c0][c1][nxt2] = max(dp[c0][c1][nxt2], dp[c0][c1][c2] + 1);
            }
        }
    }

    return res >= k;
}


void solve(){
    int lo = 1, hi = 10000, res = -1;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(check(mid)){
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    if(res == -1) cout << res << "\n";
    else cout << fixed << setprecision(6) << sqrt(res) << "\n";
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> k;
    n = 3;

    for(int i = 0; i < n; ++i){
        cin >> grid[i];

        nxt[i][m + 1] = m + 1;
        for(int j = m; j >= 1; --j){
            nxt[i][j] = nxt[i][j + 1];
            if(grid[i][j - 1] == '.') nxt[i][j] = j;
        }
    }

    solve();

    return 0;
}
