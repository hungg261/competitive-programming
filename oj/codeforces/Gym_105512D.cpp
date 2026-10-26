/******************************************************************************
Link: https://codeforces.com/gym/105512/problem/D
Code: Gym_105512D
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-26-17.31.05
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 1000, MAXM = 1000, MAXD = 2000;
int n, m, q;
int a[MAXN + 5][MAXM + 5];
int dp[2][MAXN + 5][MAXM + 5];

struct TwoBest{
    int v1, v2;
    int i1, j1;

    TwoBest(){
        v1 = v2 = -INF;
        i1 = j1 = -1;
    }

    void push(int val, int i, int j){
        if(val > v1){
            v2 = v1;
            v1 = val; i1 = i; j1 = j;
        }
        else if(val > v2){
            v2 = val;
        }
    }

    int avoid(int x, int y){
        if(i1 == x && j1 == y) return v2;
        return v1;
    }
};

TwoBest top[MAXD + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; ++i) dp[0][i][1] = dp[0][i - 1][1] + a[i][1];
    for(int i = 1; i <= m; ++i) dp[0][1][i] = dp[0][1][i - 1] + a[1][i];
    for(int i = 2; i <= n; ++i){
        for(int j = 2; j <= m; ++j){
            dp[0][i][j] = max(dp[0][i][j - 1], dp[0][i - 1][j]) + a[i][j];
        }
    }

    for(int i = n; i >= 1; --i) dp[1][i][m] = dp[1][i + 1][m] + a[i][m];
    for(int i = m; i >= 1; --i) dp[1][n][i] = dp[1][n][i + 1] + a[n][i];
    for(int i = n - 1; i >= 1; --i){
        for(int j = m - 1; j >= 1; --j){
            dp[1][i][j] = max(dp[1][i][j + 1], dp[1][i + 1][j]) + a[i][j];
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int d = i + j;
            int val = dp[0][i][j] + dp[1][i][j] - a[i][j];
            top[d].push(val, i, j);
        }
    }

    while(q--){
        int x, y, v;
        cin >> x >> y >> v;

        int d = x + y;
        int avoid = top[d].avoid(x, y);

        int through_new = dp[0][x][y] + dp[1][x][y] - 2 * a[x][y] + v;
        int res = max(avoid, through_new);
        cout << res << "\n";
    }

    return 0;
}
