/******************************************************************************
Link: https://codeforces.com/problemset/problem/1513/C
Code: 1513C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-16-20.09.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int MAXM = 2e5;
int dp[MAXM + 5];

void compute(){
    for(int i = 0; i <= 8; ++i) dp[i] = 2;
    for(int i = 9; i <= 9; ++i) dp[i] = 3;
    for(int i = 10; i <= MAXM; ++i) dp[i] = (dp[i - 9] + dp[i - 10]) % MOD;
}

void solve(){
    string s;
    int m;
    cin >> s >> m;

    int res = 0;
    for(char c: s){
        c -= '0';

        if(c + m < 10){
            res += 1;
        }
        else res += dp[c + m - 10];
        res %= MOD;
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    compute();

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
