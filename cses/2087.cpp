/******************************************************************************
Link: https://cses.fi/problemset/task/2087
Code: 2087
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-22-23.12.43
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 3000;
int n, k;
int c[MAXN + 5];
int pre[MAXN + 5], pre_c[MAXN + 5];

int sum(int l, int r){ return pre[r] - pre[l - 1]; }
int sum_c(int l, int r){ return pre_c[r] - pre_c[l - 1]; }

int med[MAXN + 5][MAXN + 5];
void precompute(){
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            med[i][j] = lower_bound(pre + i, pre + j + 1, pre[i - 1] + sum(i, j) / 2) - pre;
        }
    }
}

int cost(int l, int r){
    int m = med[l][r];
    return (m * sum(l, m) - sum_c(l, m)) + (sum_c(m, r) - m * sum(m, r));
}

int dp[2][MAXN + 5];
void computeDP(int c, int l, int r, int optL, int optR){
    if(l > r) return;

    int mid = (l + r) >> 1;
    pair<int, int> best = {LLONG_MAX, -1};
    for(int i = optL; i <= min(mid, optR); ++i)
        best = min(best, {dp[c - 1 & 1][i] + cost(i + 1, mid), i});

    int opt = best.second;
    dp[c & 1][mid] = best.first;

    computeDP(c, l, mid - 1, optL, opt);
    computeDP(c, mid + 1, r, opt, optR);
}

void solve(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int c = 1; c <= k; ++c){
        computeDP(c, 0, n, 0, n);
    }

    cout << dp[k & 1][n] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
        pre[i] = pre[i - 1] + c[i];
        pre_c[i] = pre_c[i - 1] + c[i] * i;
    }

    precompute();
    solve();

    return 0;
}
