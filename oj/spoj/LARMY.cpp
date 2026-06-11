/******************************************************************************
Link: https://www.spoj.com/problems/LARMY/
Code: LARMY
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-11-19.22.38
*******************************************************************************/
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

const int MAXN = 5000;
int n, k;
int H[MAXN + 5];

int taller[MAXN + 5][MAXN + 5];
int cost[MAXN + 5][MAXN + 5];

void compute(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            taller[i][j] = taller[i][j - 1];
            if(H[j] > H[i]) ++taller[i][j];
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            cost[i][j] = cost[i][j - 1] + (taller[j][j] - taller[j][i - 1]);
        }
    }
}

int dp[2][MAXN + 5];

void computeDP(int c, int l, int r, int optL, int optR){
    if(l > r) return;

    int mid = (l + r) >> 1;
    int lim = min(mid, optR);
    int opt = -1; dp[c][mid] = INT_MAX;
    for(int i = optL; i <= lim; ++i){
        int curCost = dp[c ^ 1][i - 1] + cost[i][mid];

        if(curCost < dp[c][mid]){
            dp[c][mid] = curCost;
            opt = i;
        }
    }

    computeDP(c, l, mid - 1, optL, opt);
    computeDP(c, mid + 1, r, opt, optR);
}

void solve(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int c = 1; c <= k; ++c){
        int b = c & 1;
        computeDP(b, 1, n, 1, n);
    }

    cout << dp[k & 1][n] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> H[i];
    }

    compute();
    solve();

    return 0;
}
