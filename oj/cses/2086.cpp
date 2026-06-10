/******************************************************************************
Link: https://cses.fi/problemset/task/2086
Code: 2086
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-22-08.43.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 3e3, MAXK = 3e3, MAXVAL = 1e5;
int n, k, arr[MAXN + 5];
int pre[MAXN + 5];

int cost(int l, int r){ return (pre[r] - pre[l - 1]) * (pre[r] - pre[l - 1]); }

int dp[MAXN + 5][MAXK + 5];
void compute(int c, int l, int r, int optL, int optR){
    if(l > r) return;

    pair<int, int> best = {LLONG_MAX, -1};
    int mid = (l + r) >> 1;

    for(int i = optL; i <= min(mid, optR); ++i){
        best = min(best, {dp[i][c - 1] + cost(i + 1, mid), i});
    }

    int opt = best.second;
    dp[mid][c] = best.first;

    compute(c, l, mid - 1, optL, opt);
    compute(c, mid + 1, r, opt, optR);
}

void solve(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    for(int c = 1; c <= k; ++c)
        compute(c, 0, n, 0, n);

    cout << dp[n][k] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }

    solve();

    return 0;
}
