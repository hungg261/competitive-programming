/******************************************************************************
Link: https://codeforces.com/gym/103536/problem/A
Code: Gym_103536A
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-11-21.22.28
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 8000, MAXK = 3000;
int n, k;
long long P[MAXN + 5];

inline long long cost(int l, int r){ return (P[r] - P[l - 1]) * (r - l + 1); }

long long dp[2][MAXN + 1];

void computeDP(int c, int l, int r, int optL, int optR){
    if(l > r) return;

    int mid = (l + r) >> 1;
    int opt = -1; dp[c][mid] = LLONG_MAX;
    for(int i = optL; i <= min(mid, optR); ++i){
        long long curCost = dp[c ^ 1][i - 1] + cost(i, mid);
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
        computeDP(c & 1, 1, n, 1, n);
    }

    cout << dp[k & 1][n] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> P[i];
        P[i] += P[i - 1];
    }

    solve();

    return 0;
}
