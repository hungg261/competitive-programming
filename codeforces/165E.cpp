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
    const int SIZE = 1 << MAXLG;
    vector<int> a(n), dp(SIZE, -1);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        dp[a[i]] = a[i];
    }

    for(int mask = 0; mask < SIZE; ++mask){
        for(int i = 0; i < MAXLG; ++i){
            if(mask >> i & 1){
                dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        cout << dp[a[i] ^ (SIZE - 1)] << " ";
    }
    cout << "\n";

    return 0;
}
