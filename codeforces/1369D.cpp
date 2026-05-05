/******************************************************************************
Link: https://codeforces.com/contest/1369/problem/D
Code: 1369D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-05-07.49.49
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e6;
int dp[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i = 3; i <= MAXN; ++i){
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
        if(i % 3 == 0) ++dp[i];

        dp[i] %= MOD;
    }

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << dp[n] * 4 % MOD << "\n";
    }

    return 0;
}
