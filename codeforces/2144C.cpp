/******************************************************************************
Link: https://codeforces.com/problemset/problem/2144/C
Code: 2144C
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-26-21.44.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 1000;
const int MOD = 998244353;
void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1, 0), b(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        if(a[i - 1] <= a[i] && b[i - 1] <= b[i]){
            dp[i] += dp[i - 1];
            dp[i] %= MOD;
        }
        if(b[i - 1] <= a[i] && a[i - 1] <= b[i]){
            dp[i] += dp[i - 1];
            dp[i] %= MOD;
        }

        dp[i] %= MOD;
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
