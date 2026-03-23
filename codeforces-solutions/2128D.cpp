#include<bits/stdc++.h>
//#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    vector<long long> dp(n + 1);
    dp[n] = 0;
    dp[n - 1] = 1; // last

    long long ans = 1;
    for(int i = n - 2; i >= 0; --i){
        if(arr[i] > arr[i + 1]) dp[i] = dp[i + 1] + n - i;
        else dp[i] = dp[i + 2] + (n - (i + 1)) + 1;
        ans += dp[i];
    }

    cout << ans << '\n';
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
