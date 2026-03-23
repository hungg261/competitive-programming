#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> dp(65);
    dp[0] = 1;
    dp[1] = 0;
    for(int i = 2; i <= n; ++i){
        dp[i] = dp[i - 2] * 2;
    }

    cout << dp[n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
