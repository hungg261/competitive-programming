/******************************************************************************
Link: https://codeforces.com/problemset/problem/165/E
Code: 165E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-31-16.23.59
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    const int MAX = 4e6, MAXLG = __lg(MAX) + 1;
    vector<int> dp(1 << MAXLG, -1);

    for(int i = 0; i < n; ++i){
        int cur; cin >> cur;
        dp[~cur & ((1 << MAXLG) - 1)] = cur;
    }

    for(int i = 0; i <= MAXLG; ++i){
        for(int mask = 1; mask <= MAX; ++mask){
            if(mask >> i & 1){
                dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
            }
        }
    }

    cout << dp[36] << '\n';

    return 0;
}
