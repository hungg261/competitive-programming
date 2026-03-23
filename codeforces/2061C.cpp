#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    arr[0] = 0;
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    vector<int> dp(n + 1);
    dp[0] = 1;

    for(int i = 1; i <= n; ++i){
        if(arr[i - 1] == arr[i]) dp[i] += dp[i - 1];
        if(i > 1 && arr[i - 2] + 1 == arr[i]) dp[i] += dp[i - 2];

        dp[i] %= MOD;
    }

    cout << (dp[n - 1] + dp[n]) % MOD << '\n';
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
