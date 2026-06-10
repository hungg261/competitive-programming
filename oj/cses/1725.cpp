#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;

    vector<double> dp(n * 6 + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; ++ i){
        for(int j = n * 6; j >= 0; --j){
            double prob = 0;
            for(int k = 1; k <= 6 && dp[j - k] >= 0; ++k){
                prob += dp[j - k];
            }

            dp[j] = prob / 6.0;
        }
    }

    double ans = 0;
    for(int sum = a; sum <= b; ++sum){
        ans += dp[sum];
    }
    cout << fixed << setprecision(6) << ans << '\n';

    return 0;
}
