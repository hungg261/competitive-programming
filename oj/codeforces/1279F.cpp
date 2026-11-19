/******************************************************************************
Link: https://codeforces.com/contest/1279/problem/F
Code: 1279F
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-19-17.33.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e12 + 5;
const int MAXN = 1e6;
int n, k, l;
string s;

namespace Brute{

int subsolve(const vector<int>& a){
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

    for(int j = 0; j <= k; ++j) dp[0][j] = 0;

    for(int i = 1; i <= n; ++i){
        dp[i][0] = dp[i - 1][0] + a[i];
        for(int j = 1; j <= k; ++j){
            dp[i][j] = min(dp[i - 1][j] + a[i], dp[max(0LL, i - l)][j - 1]);
        }
    }

    return dp[n][k];
}

void solve(){
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        if('a' <= s[i] && s[i] <= 'z') a[i] = 1;
        else a[i] = 0;
    }

    int res = subsolve(a);
    for(int i = 1; i <= n; ++i) a[i] = 1 - a[i];
    res = min(res, subsolve(a));

    cout << res << "\n";
}

}

namespace Solve{

pair<int, int> get(int cost, const vector<int> &a){
    vector<pair<int, int>> dp(n + 1);
    dp[0] = {0, 0};

    for(int i = 1; i <= n; ++i){
        int last = max(0LL, i - l);
        int v1 = dp[last].first + cost, v2 = dp[i - 1].first + a[i];

        dp[i].first = min(v1, v2);
        if(v1 < v2) dp[i].second = dp[last].second + 1;
        else if(v1 > v2) dp[i].second = dp[i - 1].second;
        else
            dp[i].second = max(dp[last].second + 1, dp[i - 1].second);
    }

    return dp[n];
}

int subsolve(const vector<int> &a){
    int lo = 0, hi = INF, best_cost = 0;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        int cur_dp, cur_cnt;
        tie(cur_dp, cur_cnt) = get(mid, a);

        if(cur_cnt >= k){
            best_cost = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    return get(best_cost, a).first - k * best_cost;
}

void solve(){
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        if('a' <= s[i] && s[i] <= 'z') a[i] = 1;
        else a[i] = 0;
    }

    int res = subsolve(a);
    for(int i = 1; i <= n; ++i) a[i] = 1 - a[i];
    res = min(res, subsolve(a));

    cout << res << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> l;
    cin >> s;

    n = s.size();
    s = "#" + s;

    Solve::solve();

    return 0;
}
