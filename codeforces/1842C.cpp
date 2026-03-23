/******************************************************************************
Link: https://codeforces.com/problemset/problem/1842/C
Code: 1842C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-13-10.10.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<int> last(n + 1, -1), jump(n + 1, -1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];

        int& prv = last[arr[i]];
        if(prv != -1) jump[i] = prv;

        prv = i;
    }

    vector<int> dp(n + 1), opt(n + 1, -1e9);
    dp[0] = 0;

    for(int i = 1; i <= n; ++i){
        dp[i] = max(dp[i - 1], opt[arr[i]] + i + 1);
        opt[arr[i]] = max(opt[arr[i]], dp[i - 1] - i);
    }

    int res = 0;
    for(int i = 1; i <= n; ++i){
        res = max(res, dp[i]);
    }
    cout << res << '\n';
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
