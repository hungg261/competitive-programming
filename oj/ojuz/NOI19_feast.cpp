/******************************************************************************
Link: https://oj.uz/problem/view/NOI19_feast
Code: NOI19_feast
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-19-14.53.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 3e5, MAXVAL = 1e9;
int n, k;
int a[MAXN + 5];

pair<int, int> get(int cost){
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(2));

    dp[0][0].first = 0; dp[0][1].first = -INF;
    dp[0][0].second = 0; dp[0][1].second = 0;

    for(int i = 1; i <= n; ++i){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

        int v1 = dp[i - 1][0].first + a[i] - cost, v2 = dp[i - 1][1].first + a[i];
        dp[i][1].first = max(v1, v2);

        if(v1 > v2) dp[i][1].second = dp[i - 1][0].second + 1;
        else if(v1 < v2) dp[i][1].second = dp[i - 1][1].second;
        else
            dp[i][1].second = max(dp[i - 1][0].second + 1, dp[i - 1][1].second);
    }

    pair<int, int> res = max(dp[n][0], dp[n][1]);
    return res;
}

void solve(){
    int lo = 0, hi = MAXN * MAXVAL + 5, best_cost = 0;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        int cur_dp, cur_cnt;
        tie(cur_dp, cur_cnt) = get(mid);

        if(cur_cnt >= k){
            best_cost = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    cout << get(best_cost).first + k * best_cost << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    solve();

    return 0;
}
