/******************************************************************************
Link: https://atcoder.jp/contests/abc447/tasks/abc447_d
Code: abc447_d
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-28-19.16.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int dp[100005][3];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string S;
    cin >> S;

    int n = S.size();
    S = "#" + S;

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 3; ++j) dp[i][j] = dp[i - 1][j];
        if(S[i] == 'A') dp[i][0] = max(dp[i][0], dp[i - 1][2] + 1);
        else if(S[i] == 'B') dp[i][1] = max(dp[i][1], dp[i - 1][0]);
        else dp[i][2] = max(dp[i][2], dp[i - 1][1]);
    }

    for(int i = 1; i <= n; ++i){
        cerr << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
    }

    cout << dp[n][2] << '\n';

    return 0;
}
