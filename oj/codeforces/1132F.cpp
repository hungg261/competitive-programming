/******************************************************************************
Link: https://codeforces.com/contest/1132/problem/F
Code: 1132F
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-29-16.37.59
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500;
string s;
int n;
int dp[MAXN + 5][MAXN + 5];

void solve(){
    for(int len = 1; len <= n; ++len){
        for(int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;

            dp[i][j] = 1 + dp[i + 1][j];
            for(int k = i; k <= j; ++k){
                if(s[i] == s[k])
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
            }
        }
    }

    cout << dp[1][n] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;
    n = s.size();
    s = "#" + s;

    solve();

    return 0;
}
