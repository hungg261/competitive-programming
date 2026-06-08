/******************************************************************************
Link: https://codeforces.com/gym/105675/problem/7
Code: Gym_1056757
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-08-19.51.43
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 23;

void solve(){
    int n, s;
    cin >> n >> s;

    vector<vector<int>> c(n + 1);
    for(int i = 1; i <= n; ++i){
        int k; cin >> k;
        c[i].resize(k);
        for(int j = 0; j < k; ++j){
            cin >> c[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        dp[i] = dp[i - 1];
        for(int a: c[i]){
            for(int j = s; j >= a; --j)
                dp[i][j] = (1LL * dp[i][j] + dp[i][j - a]) % MOD;
        }

        for(int j = 0; j <= s; ++j){
            if(dp[i][j] == dp[i - 1][j]) dp[i][j] = 0;
        }
    }

    bool ok = dp[n][s];
    cout << (ok ? "Yes\n" : "No\n");

    if(!ok) return;

    vector<vector<int>> res(n + 1);
    for(int i = n; i >= 1; --i){
        int k = c[i].size();
        vector<vector<int>> f(k + 1, vector<int>(s + 1, 0));
        f[0][0] = 1;
        for(int j = 1; j <= k; ++j){
            int a = c[i][j - 1];
            for(int m = s; m >= 0; --m){
                f[j][m] |= f[j - 1][m];
                if(m >= a) f[j][m] |= f[j - 1][m - a];
            }
        }

        int contrib = 0;
        for(int j = s; j >= 1; --j){
            if(dp[i - 1][s - j] && f[k][j]){
                contrib = j;
                s -= j;
                break;
            }
        }

        for(int m = k - 1; m >= 0; --m){
            if(contrib >= c[i][m] && f[m][contrib - c[i][m]]){
                res[i].push_back(m + 1);
                contrib -= c[i][m];
            }
        }
        reverse(begin(res[i]), end(res[i]));
    }

    for(int i = 1; i <= n; ++i){
        cout << res[i].size() << "\n";
        for(int idx: res[i]){
            cout << idx << " ";
        }
        cout << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();


    return 0;
}
