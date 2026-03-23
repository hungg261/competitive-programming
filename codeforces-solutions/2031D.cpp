#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    int k = __lg(n) + 1;
    vector<vector<pair<int, int>>> table(n + 1, vector<pair<int, int>>(k + 1));
    for(int i = 1; i <=n; ++i){
        cin >> table[i][0].first;
        table[i][0].second = table[i][0].first;
    }

    for(int j = 1; j <= k; ++j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++i){
            table[i][j] = {
                            min(table[i][j - 1].first, table[i + (1 << j - 1)][j - 1].first),
                            max(table[i][j - 1].second, table[i + (1 << j - 1)][j - 1].second)
                        };
        }
    }

    auto queryMin = [&table](int l, int r){
        int bit = __lg(r - l + 1);
        return min(table[l][bit].first, table[r - (1 << bit) + 1][bit].first);
    };
    auto queryMax = [&table](int l, int r){
        int bit = __lg(r - l + 1);
        return max(table[l][bit].second, table[r - (1 << bit) + 1][bit].second);
    };

    vector<int> dp(n + 1);
    dp[n] = queryMax(1, n);

    for(int i = n - 1; i >= 1; --i){
        int L = queryMax(1, i), R = queryMin(i + 1, n);
        if(L > R) dp[i] = max(L, dp[i + 1]);
        else dp[i] = L;
    }

    for(int i = 1; i <= n; ++i){
        cout << dp[i] << ' ';
    }
    cout << '\n';
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
