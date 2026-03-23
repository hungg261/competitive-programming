/******************************************************************************
Link: https://codeforces.com/problemset/problem/1987/C
Code: 1987C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-16-09.17.42
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> h(n + 1), dp(n + 1);
    for(int i = 1; i <= n; ++i) cin >> h[i];

    dp[n] = h[n];
    for(int i = n - 1; i >= 1; --i){
        dp[i] = max(h[i], dp[i + 1] + 1);
    }

    cout << dp[1] << '\n';
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
