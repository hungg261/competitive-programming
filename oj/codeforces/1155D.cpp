/******************************************************************************
Link: https://codeforces.com/contest/1155/problem/D
Code: 1155D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-17-16.09.43
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 3e5;
int n, x;
int arr[MAXN + 5];

int dp[3];
void solve(){
    dp[0] = dp[1] = 0;
    dp[2] = LLONG_MIN / 2;
    int res = 0;
    for(int i = 1; i <= n; ++i){
        dp[2] = max({dp[1] + arr[i], dp[2] + arr[i]});
        dp[1] = max({arr[i] * x, dp[1] + arr[i] * x, dp[0] + arr[i] * x});
        dp[0] = max(arr[i], dp[0] + arr[i]);

        res = max({res, dp[0], dp[1], dp[2]});
    }

    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    solve();

    return 0;
}
