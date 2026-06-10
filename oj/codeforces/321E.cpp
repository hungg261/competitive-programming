/******************************************************************************
Link: https://codeforces.com/contest/321/problem/E
Code: 321E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-08-08.51.20
*******************************************************************************/
#include<bits/stdc++.h>
#ifdef _WIN32
#define GETCHAR _getchar_nolock
#else
#define GETCHAR getchar_unlocked
#endif
using namespace std;

inline int readInt() {
    int x = 0;
    char ch = GETCHAR();
    while (ch < '0' || ch > '9') {
        if (ch == EOF) return -1;
        ch = GETCHAR();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = GETCHAR();
    }
    return x;
}

const int MAXN = 4000, MAXK = 800;
int u[MAXN + 5][MAXN + 5];
int cost[MAXN + 5][MAXN + 5];
int pre[MAXN + 5][MAXN + 5];
int n, k;

void compute(){
    for(int j = 1; j <= n; ++j){
        for(int i = 1; i <= n; ++i){
            pre[i][j] = pre[i - 1][j] + u[i][j];
        }
    }

    for(int i = 1; i <= n; ++i){
        int c = 0;
        for(int j = i; j <= n; ++j){
            c += pre[j][j] - pre[i - 1][j];
            cost[i][j] = c;
        }
    }
}

int dp[MAXK + 5][MAXN + 5];
void computeDp(int c, int l, int r, int optL, int optR){
    if(l > r) return;

    int mid = (l + r) >> 1;
    pair<int, int> best = {INT_MAX, -1};
    for(int j = optL; j <= min(optR, mid); ++j){
        best = min(best, {dp[c - 1][j - 1] + cost[j][mid], j});
    }

    dp[c][mid] = best.first;
    int opt = best.second;

    computeDp(c, l, mid - 1, optL, opt);
    computeDp(c, mid + 1, r, opt, optR);
}

void solve(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    for(int c = 1; c <= k; ++c){
        computeDp(c, 1, n, 1, n);
    }

    cout << dp[k][n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    n = readInt();
    k = readInt();
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            u[i][j] = readInt();
        }
    }

    compute();
    solve();

    return 0;
}
