#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[1][0] = min(0 - a[1], b[1] - 0);
    dp[1][1] = max(0 - a[1], b[1] - 0);

    for(int i = 2; i <= n; ++i){
        dp[i][0] = min({dp[i - 1][0] - a[i], b[i] - dp[i - 1][1]});
        dp[i][1] = max({dp[i - 1][1] - a[i], b[i] - dp[i - 1][0]});
    }

    cout << dp[n][1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}
