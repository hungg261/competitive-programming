/******************************************************************************
Link: https://codeforces.com/contest/2133/problem/D
Code: 2133D
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-20-19.51.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> h(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> h[i];
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = h[1];
    for(int i = 2; i <= n; ++i){
        dp[i] = min(dp[i - 1] + h[i] - 1, dp[i - 2] + h[i - 1] + max(0LL, h[i] - (i - 1)));
    }

    cout << dp[n] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
