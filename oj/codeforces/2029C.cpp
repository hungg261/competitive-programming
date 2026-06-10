/******************************************************************************
Link: https://codeforces.com/contest/2029/problem/C
Code: 2029C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-01-07.35.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int dp[MAXN + 5][3];

int f(int x, int y){
    if(x < y) return 1;
    if(x > y) return -1;
    return 0;
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    dp[0][0] = 0;
    dp[0][1] = -1e9;
    dp[0][2] = -1e9;
    for(int i = 1; i <= n; ++i){
        dp[i][0] = dp[i - 1][0] + f(dp[i - 1][0], arr[i]);
        dp[i][1] = max(
                        dp[i - 1][0],
                        dp[i - 1][1]
                    );
        dp[i][2] = max(
                        dp[i - 1][1] + f(dp[i - 1][1], arr[i]),
                        dp[i - 1][2] + f(dp[i - 1][2], arr[i])
                    );
    }

    int ans = max(dp[n][1], dp[n][2]);
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
