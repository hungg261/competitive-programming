#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int f(int x){ return x & 1; }

const int INF = 1e9 + 7;
void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(k + 1, -INF)));
    dp[0][0][0] = 0;

    for(int i = 0; i < n; ++i){
        for(int s = 0; s <= k; ++s){
            for(int m = 0; m <= k; ++m){
                for(int v = 0; v <= min(k - s, a[i + 1]); ++v){
                    int newSum = s + v, newMax = max(m, v);
                    dp[i + 1][newSum][newMax] = max(dp[i + 1][newSum][newMax], dp[i][s][m] + newMax);
                }
            }
        }
    }

    int ans = 0;
    for(int s = 0; s <= k; ++s){
        for(int m = 0; m <= k; ++m){
            ans = max(ans, dp[n][s][m]);
        }
    }

    cout << ans << '\n';
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
