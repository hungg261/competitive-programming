#include<bits/stdc++.h>
using namespace std;

void solve(){
    string A, B, C;
    int a, b;

    cin >> A >> B >> C;
    a = A.size();
    b = B.size();

    A = "#" + A;
    B = "#" + B;
    C = "#" + C;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    dp[0][0] = 0;
    for(int i = 1; i <= a; ++i) dp[i][0] = dp[i - 1][0] + (A[i] != C[i]);
    for(int j = 1; j <= b; ++j) dp[0][j] = dp[0][j - 1] + (B[j] != C[j]);

    for(int i = 1; i <= a; ++i){
        for(int j = 1; j <= b; ++j){
            int L = dp[i - 1][j] + (A[i] != C[i + j]);
            int R = dp[i][j - 1] + (B[j] != C[i + j]);

            dp[i][j] = min(L, R);
        }
    }

    cout << dp[a][b] << '\n';
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
