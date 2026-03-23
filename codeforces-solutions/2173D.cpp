#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    if(n == 0){
        cout << min(0LL, k - 1) << '\n';
        return;
    }

    int bitcnt = __builtin_popcount(n);
    if(k >= 33){
        cout << bitcnt + k - 1 << '\n';
        return;
    }

    const int INF = 1e9;
    vector<vector<vector<int>>> dp(65, vector<vector<int>>(k + 5, vector<int>(2, INF)));
    dp[0][0][0] = 0;
    for(int i = 0; i < 64; ++i){
        int ni = n >> i & 1LL;
        for(int j = 0; j <= k; ++j){
            for(int c = 0; c < 2; ++c){

                {
                    int sum = ni + c, nxt_bit = sum & 1, nxt_c = sum >> 1;
                    dp[i + 1][j][nxt_c] = min(dp[i + 1][j][nxt_c], dp[i][j][c] + nxt_bit);
                }

                {
                    int sum = ni + c + 1, nxt_bit = sum & 1, nxt_c = sum >> 1;
                    dp[i + 1][j + 1][nxt_c] = min(dp[i + 1][j + 1][nxt_c], dp[i][j][c] + nxt_bit);
                }
            }
        }
    }

    int sub = INF;
    for(int j = 0; j <= k; ++j){
        for(int c = 0; c < 2; ++c){
            sub = min(sub, dp[64][j][c] + c);
        }
    }

    int ans = bitcnt + k - sub;
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
