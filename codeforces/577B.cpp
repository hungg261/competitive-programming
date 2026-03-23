#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    if(n > m){
        cout << "YES\n";
        return;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m, false));
    for(int i = 1; i <= n; ++i){
        dp[i][arr[i] % m] = true;
        for(int j = 0; j < m; ++j){
            dp[i][j] |= dp[i - 1][j];
            dp[i][j] |= dp[i - 1][(j - arr[i] % m + m) % m];
        }
    }

    cout << (dp[n][0] ? "YES" : "NO") << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
