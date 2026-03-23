#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    string a, b;

    cin >> a >> b;
    n = a.size(), m = b.size();
    a = '#' + a, b = '#' + b;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i <= n; ++i) dp[i][0] = i;
    for(int j = 0; j <= m; ++j) dp[0][j] = j;


    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }

        }
    }

    cout << dp[n][m] << '\n';
    return 0;
}
