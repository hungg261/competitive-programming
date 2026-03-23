/******************************************************************************
Link: https://codeforces.com/problemset/problem/1875/D
Code: 1875D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-06-22.03.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    sort(begin(arr), end(arr));

    vector<int> cnt(n);
    for(int i = 1; i <= n; ++i){
        if(arr[i] < n) ++cnt[arr[i]];
    }

    int mex = 0;
    for(; mex < n; ++mex){
        if(cnt[mex] == 0) break;
    }

    vector<int> dp(mex + 1, 1e9);
    dp[mex] = 0;
    for(int i = mex - 1; i >= 0; --i){
        for(int j = i; j <= mex; ++j){
            dp[i] = min(dp[i], dp[j] + (cnt[i] - 1) * j + i);
        }
    }

    cout << dp[0] << '\n';
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
