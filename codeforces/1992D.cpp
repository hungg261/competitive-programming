#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    string S;
    cin >> S;

    S = 'L' + S + 'L';

    vector<int> dp(n + 2, -1);

    dp[0] = 0;
    for(int i = 1; i <= n + 1; ++i){
        if(S[i] == 'C') continue;

        dp[i] = 1e9;
        if(S[i - 1] == 'W' && dp[i - 1] != -1){
            if(S[i] == 'L') dp[i] = dp[i - 1];
            else if(S[i] == 'W' && dp[i - 1] + 1 <= k) dp[i] = dp[i - 1] + 1;
        }

        for(int j = i - 1; j >= i - m && j >= 0; --j){
            if(S[j] == 'L' && dp[j] != -1){
                if(S[i] == 'L') dp[i] = min(dp[i], dp[j]);
                else if(S[i] == 'W' && dp[j] + 1 <= k) dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        if(dp[i] == (int)1e9) dp[i] = -1;
    }

    bool ok = dp[n + 1] != -1 && dp[n + 1] <= k;
    cout << (ok ? "YES" : "NO") << '\n';
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
