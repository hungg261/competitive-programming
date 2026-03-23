#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    string S[n + 1];
    for(int i = 1; i <= n; ++i){
        cin >> S[i];
        S[i] = '#' + S[i];
    }

    bool dp[m + 1][5] = {};

    dp[0][0] = true;
    for(int j = 1; j <= m; ++j){
        memcpy(dp[j], dp[j - 1], sizeof dp[j]);
        for(int i = 1; i <= n; ++i){
            if(S[i][j] == 'v') dp[j][1] |= dp[j - 1][0];
            else if(S[i][j] == 'i') dp[j][2] |= dp[j - 1][1];
            else if(S[i][j] == 'k') dp[j][3] |= dp[j - 1][2];
            else if(S[i][j] == 'a') dp[j][4] |= dp[j - 1][3];
        }
    }

    cout << (dp[m][4] ? "YES" : "NO") << '\n';
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
