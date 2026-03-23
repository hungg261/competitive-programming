#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;

    vector<int> w(n);
    for(int& ele: w) cin >> ele;

    vector<pair<int, int>> dp(1 << n);
    dp[0] = {1, 0};

    for(int mask = 1; mask < (1 << n); ++mask){
        dp[mask] = {1e9, 1e9};

        for(int i = 0; i < n; ++i){
            if(mask & (1 << i)){
                auto prev = dp[mask ^ (1 << i)];

                if(prev.second + w[i] <= x) prev.second += w[i];
                else{
                    ++prev.first;
                    prev.second = w[i];
                }

                dp[mask] = min(dp[mask], prev);
            }
        }
    }

    cout << dp[(1 << n) - 1].first << '\n';

    return 0;
}
